from app import app
from flask import request,Response,jsonify
import serial, time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port

i = 1  #led number
a = str(i)
ans = 0

@app.route('/cell', methods=['GET'])
def cell():
    response = Response() 
    try: 
        #a = request.form['n']
        i = request.args.get('n')
        a = str(i)
        ser.write(str.encode(a))
        print("OK")
        for line in ser.read():   # ans from driver Serial Port
            print( "ans from drv = ", line )
            try:
                ans = int(line)
            except: 
                ans = 3 # error ans from driver, not a number      
    except:
        print("NO")
    #time.sleep(5)
    response.headers["Content-Type"]="text/plain"
    ##Control result
    result = ans#1
    body = {"state":result}
    response.status_code = 200
    response.data = body
    return response #"Hello, World!"
   


