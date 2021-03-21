import serial, time
ser = serial.Serial('/dev/ttyACM0', 115200, timeout = 0.1)    #Open named port
i = 0
while i < 32:
    a = str(i) + '\n'
    ser.write(str.encode(a))
    time.sleep(0.3);
    i += 1
ser.close()
