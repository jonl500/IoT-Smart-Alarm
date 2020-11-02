import serial
import time

arduino = serial.Serial('/dev/ttyUSB0', 9600)
arduino.write(b'53'.encode())
print(arduino.readline())