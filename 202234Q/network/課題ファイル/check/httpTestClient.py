# Echo client program
import socket
# リモート（サーバ）ホスト名
HOST = 'localhost'
# リモート（サーバ）ホストのポート番号
port = int(input())
# リモート（サーバ）上のファイル名
file = input()
# GET リクエスト
req = f"GET /{file} HTTP/1.1\nHost: {HOST}\n\n".encode()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, port))
    s.sendall(req)
    print('Send', repr(req.decode()))
    data = s.recv(1024)
    print('Received', data.decode())