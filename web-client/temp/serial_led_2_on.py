#import requests
import serial
ser = serial.Serial ("/dev/serial1")    #Open named port
ser.baudrate = 115200                     #Set baud rate to 9600
# data = ser.read(10)                     #Read ten characters from serial port to data
ser.write(b'2\n')                         #Send back the received data

ser.close()


