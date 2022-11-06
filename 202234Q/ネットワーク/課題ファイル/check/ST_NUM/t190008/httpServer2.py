# HTTP server program
import socket
 
port = int(input())
while port < 1024:
    print('ポート番号は1024以上しか使えません')
    port = int(input())
file = input()
cType = b"Content-Type: text/html; charset=utf-8\n\n"
htHead = b"<html><body>"
htTail = b"</html></body>"
# 繧ｵ繝ｼ繝舌�繧ｹ繝亥錐��'' 縺ｨ縺吶ｋ縺ｨ螳溯｡後�繧ｷ繝ｳ荳翫�謗･邯壼庄閭ｽ縺ｪ蜈ｨ縺ｦ縺ｮ繝帙せ繝亥錐��
HOST = ""
print(f"port={port}, file={file}")
 
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # setsockopt() 縺ｫ縺､縺�※縺ｯ隨ｬ5蝗槭�繝ｼ繧ｸ縺ｮ繝｡繝｢繧貞盾辣ｧ
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
            # 謾ｹ陦後＠縺ｪ縺�
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