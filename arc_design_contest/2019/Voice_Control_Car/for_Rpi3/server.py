import socket
import serial
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
host = '192.168.1.109'
port = 10000
s.bind((host, port))

ser = serial.Serial('/dev/serial0', 115200, timeout=None,parity=serial.PARITY_NONE)
s.listen(5)
print 'Server start at: '+str(host)+':'+str(port)
print 'Wait for connection...'
while True:
    try:
        c, addr = s.accept()
        print 'Connected by '+str(addr)
        while True:
            try:
                rcv = str(c.recv(1024))
                print 'From client: '+rcv
                c.send("received!")
                ser.write("{}\r\n".format(rcv))
                print 'write!'  
            except:
                break
    except KeyboardInterrupt:
        ser.close()
        s.close()
        print 'close...'
        break
