import requests
import time
#import serial
#ser = serial.Serial ("/dev/ttyAMA0")    #Open named port 
#ser.baudrate = 9600                     #Set baud rate to 9600
# data = ser.read(10)                     #Read ten characters from serial port to data

session = requests.Session()

while True:
    response = session.get('http://178.140.18.140:3141/cell')
    while response.text == "":
        response = session.get('http://178.140.18.140:3141/cell')
        time.sleep(0.3)
    text = response.text
    cell = int(text)
    if 1 < cell < 32:
        print(cell)
        #ser.write(cell)                         #Send back the received data

ser.close()       

    