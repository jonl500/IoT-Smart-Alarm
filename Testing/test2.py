import serial
import time

arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2) # Need 2s delay after declaration of arduino
arduino.write(b'51')
arduino.close()
