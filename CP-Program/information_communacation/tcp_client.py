import socket

HOST = '172.20.10.10'  # 請改成Server那台機器的內網IP
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    message = 'Hello Server, this is Client'
    s.sendall(message.encode())
    data = s.recv(1024)
    print('Received from server:', data.decode())
