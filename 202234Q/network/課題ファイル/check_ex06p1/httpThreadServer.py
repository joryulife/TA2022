# HTTP server program
import socket
import threading
 
port = 50080
file = "./05/server.html"
cType = b"Content-Type: text/html; charset=utf-8\n\n"
htHead = b"<html><body>"
htTail = b"</html></body>"
# サーバホスト名（'' とすると実行マシン上の接続可能な全てのホスト名）
HOST = ""
print(f"port={port}, file={file}")
 
def httpResponse(conn, addr):
    with conn:
        print("Connected by,", addr)
        data = b""
        while True:
            data += conn.recv(1024)
            if b"\n\n" or b"\n\r\n\r" in data:
                break
        # 改行しない
        print("Received:", data.decode(), end="")
 
        rData = b"HTTP/1.1 "
        if data.startswith(b"GET "):
            try:
                with open(file,encoding="utf-8") as f:
                    rData += b"200 OK\n" + cType
                    rData += f.read().encode() + b"\n"
            except OSError:
                rData += b"404 Not Found\n" + cType
                rData += htHead + file.encode() + b" is not found" + htTail
 
        conn.sendall(rData)
        print("Sent:", rData.decode())
        conn.close()
 
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # setsockopt() については第5回ページのメモを参照
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
    s.bind((HOST, port))
    while True:
        s.listen(1)
        conn, addr = s.accept()
        th = threading.Thread(target=httpResponse, args=(conn, addr))
        th.start()
"""         with conn:
            print("Connected by,", addr)
            data = b""
            while True:
                data += conn.recv(1024)
                if b"\n\n" or b"\n\r\n\r" in data:
                    break
            # 改行しない
            print("Received:", data.decode(), end="")
 
            rData = b"HTTP/1.1 "
            if data.startswith(b"GET "):
                try:
                    with open(file,encoding="utf-8") as f:
                        rData += b"200 OK\n" + cType
                        rData += f.read().encode() + b"\n"
                except OSError:
                    rData += b"404 Not Found\n" + cType
                    rData += htHead + file.encode() + b" is not found" + htTail
 
            conn.sendall(rData)
            print("Sent:", rData.decode())
            conn.close() """