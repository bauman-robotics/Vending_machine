import serial, time
ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port
i = 1
while True:
    try:
        if i<65:
            a = str(i)
            ser.write(str.encode(a))
            time.sleep(0.3);
            i += 1
            print(i)
        else: 
            i = 1
    except:
        print("not number")        
        time.sleep(0.3);
    
ser.close()
