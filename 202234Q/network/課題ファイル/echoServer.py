# Echo server program
import socket
# サーバホスト名（カラ文字列にすると実行マシン上の接続可能な全てのホスト名）
HOST = ''
# サーバポート番号
PORT = 50007

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))

    while(True):
        s.listen(1)
        conn, addr = s.accept()
        with conn:
            print('Connected by', addr)
            while True:
                data = conn.recv(1024)
                if not data: break
                print('Received', repr(data))
                conn.sendall(data)
                print('Send', repr(data))