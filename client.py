import hashlib
from getpass import getpass
import socket
sock = socket.socket()
sock.connect(('192.168.1.38', 9090))

def login():
    print("Enter your login: ", end = ''),
    login = input()
    password = getpass()
    sock.send(login.encode('utf-8'))
    sock.send(password.encode('utf-8'))
    print(sock.recv(16))
    #password = hashlib.md5(login.encode('utf-8')).hexdigest()


login()
while True:

    msg = input()
    msg = msg.encode('utf-8')
    sock.send(msg)
sock.close()

