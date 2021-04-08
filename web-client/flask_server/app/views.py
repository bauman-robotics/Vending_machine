from app import app
from flask import request,Response,jsonify
import serial, time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port

i = 16  #led number
a = str(i)

@app.route('/cell', methods=['GET'])
def cell():
    response = Response() 
    try: 
        #a = request.form['n']
        i = request.args.get('n')
        a = str(i)
        ser.write(str.encode(a))
        print("OK")
    except:
        print("NO")
    time.sleep(5)
    response.headers["Content-Type"]="text/plain"
    ##Control result
    result = 1
    body = {"state":result}
    response.status_code = 200
    response.data = body
    return response #"Hello, World!"
   


