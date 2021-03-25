import requests
import time
import serial
ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port

while True:
    for line in ser.read():
        print( "ans_from_drv", line )
		requests.post('http://178.140.18.140:3141/cell', data={"status":"", "num":a, "clientID":1})
    response = requests.get('http://178.140.18.140:3141/cell')
    while response.text == "":
        response = requests.get('http://178.140.18.140:3141/cell')
        time.sleep(0.3)
    try:
        text = response.text
        cell = int(text)
        if 0 < cell < 65:
            print(cell)
            #a = str(cell) + '\n'
            a = str(cell)
            ser.write(str.encode(a))
            #requests.post('http://178.140.18.140:3141/cell', data={"status":"", "num":a, "clientID":1})
    except:
        print("not number")
        requests.post('http://178.140.18.140:3141/cell', data={"status":"not number"})

ser.close()       

    
