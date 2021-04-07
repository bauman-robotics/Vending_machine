from app import app
from flask import request
import serial, time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port

i = 16  #led number
a = str(i)

@app.route('/cell', methods=['GET'])
def cell():
    try: 
        i = request.args.get('n')
        a = str(i)
        ser.write(str.encode(a))
        print("OK")
    except:
        print("NO")
    return "Hello, World!"
   


