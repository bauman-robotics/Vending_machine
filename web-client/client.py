import requests
import time
import serial
ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port

session = requests.Session()

while True:
    response = session.get('http://178.140.18.140:3141/cell')
    while response.text == "":
        response = session.get('http://178.140.18.140:3141/cell')
        time.sleep(0.3)
    text = response.text
    cell = int(text)
    if 0 < cell < 32:
        print(cell)
        a = str(cell) + '\n'
        ser.write(str.encode(a))

ser.close()       

    