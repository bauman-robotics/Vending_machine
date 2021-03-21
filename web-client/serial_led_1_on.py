#import requests
import serial
ser = serial.Serial ("/dev/serial1")    #Open named port
ser.baudrate = 115200                     #Set baud rate to 9600
ser.write(b'begin\n')
#ser.write(b'1')                         #Send back the received data
ser.close()


