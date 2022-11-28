# HTTP server program
import socket
port = int(input())
while port < 1024 :
    print("ポート番号は1024以上しか使えません")
    port = int(input())
file = input()
cType = b"Content-Type: text/html; charset=utf-8\n\n"
htHead = b"<html><body>"
htTail = b"</html></body>"
# サーバホスト名（'' とすると実行マシン上の接続可能な全てのホスト名）
HOST = ""
print(f"port={port}, file={file}")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # setsockopt() については第5回ページのメモを参照
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
    s.bind((HOST, port))
    while True:
        s.listen(1)
        conn, addr = s.accept()
        with conn:
            print("Connected by,", addr)
            data = b""
            while True:
                data += conn.recv(1024)
                if b"\n\n" or "\n\r\n\r" in data:
                    break
            # 改行しない
            print("Received:", data.decode(), end="")

            rData = b"HTTP/1.1 "
            if data.startswith(b"GET "):
                try:
                    with open(file) as f:
                        rData += b"200 OK\n" + cType
                        rData += f.read().encode() + b"\n"
                except OSError:
                    rData += b"404 Not Found\n" + cType
                    rData += htHead + file.encode() + b" is not found" + htTail

            conn.sendall(rData)
            print("Sent:", rData.decode())
            conn.close()