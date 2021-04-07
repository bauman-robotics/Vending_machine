#!/usr/bin/python
import serial, time
ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)
i = 1  #led number
a = str(i)
 
try:                      
    ser.write(str.encode(a))
    print("OK")
except:
    print("NO") 
ser.close()


