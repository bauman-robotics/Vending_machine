#!/usr/bin/python
#import requests
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout = 0.1)    #Open named port
#ser.baudrate = 115200                     #Set baud rate to 9600
ser.write(b'2\n')
#ser.write(b'1')                         #Send back the received data
ser.close()


