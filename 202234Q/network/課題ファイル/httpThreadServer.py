# HTTP thread server program
import socket
import threading

port = 50007
file = "server.html"

def httpResponse(connection, address):
    with connection:
        print("Connected by,", address)
        data = b""
        while True:
            data += connection.recv(1024)
            if b"\n\n" or b"\n\r\n\r" in data:
                break
        print("Received:", data.decode(), end="")  # 改行しない

        rData = b"HTTP/1.1 "
        cType = b"Content-Type: text/html; charset=utf-8\r\n\r\n"
        htHead = b"<html><body>"
        htTail = b"</html></body>"

        if data.startswith(b"GET "):
            try:
                with open(file) as f:
                    rData += b"200 OK\r\n" + cType
                    rData += f.read().encode() + b"\r\n"
            except OSError:
                rData += b"404 Not Found\r\n" + cType
                rData += htHead + file.encode() + b" is not found" + htTail

        connection.sendall(rData)
        print("Sent:", rData.decode())
        connection.close()


if __name__ == "__main__":
    HOST = ""  # サーバホスト名（'' とすると実行マシン上の接続可能な全てのホスト名）
    print("port=", port, ", file=", file)

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)  # ex2.1-2 メモを参照
        s.bind((HOST, port))
        s.listen(1)
        while True:
            conn, addr = s.accept()
            # httpResponse(conn, addr)
            http_thread = threading.Thread(target=httpResponse, args=(conn, addr))
            http_thread.start()