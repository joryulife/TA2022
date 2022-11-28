# Echo client program
import socket
# リモート（サーバ）ホスト名
HOST = 'localhost'
# リモート（サーバ）ホストのポート番号
PORT = 50007

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    send= b'Hello, world'
    s.sendall(send)
    print('Send', repr(send))
    data = s.recv(1024)
    print('Received', repr(data))