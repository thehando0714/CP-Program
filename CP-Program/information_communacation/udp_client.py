import socket

SERVER_IP = '172.20.10.10'  # 改為server那台的IP
PORT = 65433

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    message = 'Hello Server, this is UDP Client'
    s.sendto(message.encode(), (SERVER_IP, PORT))
    data, _ = s.recvfrom(1024)
    print('Received from server:', data.decode())