import serial
import time

def toInt(bitter):
	k = 0
	for t in bitter:
		k = (k*10) + (int.from_bytes(t,byteorder='big',signed=False)-48)
	return k

arduino = serial.Serial('/dev/ttyACM0', 9600)
stream = []

while 1:
	b = arduino.read_until(size=1)
	#print(b)
	if b != b'\r' and b != b'\n':
		stream.append(b)
	elif b == b'\n':
		print(toInt(stream))
		stream = []
	#print(int.from_bytes(arduino.read_until(size=4),byteorder='little'))

# (55).to_bytes(4,byteorder='big')
# >>> b'\x00\x00\x007'
# int.from_bytes(b'\x00\x00\x007','big')
# >>> 55