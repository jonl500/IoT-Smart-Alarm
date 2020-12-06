import smtplib
import ssl
import serial
import time


#recipients is a list of emails
def relay(recipients, subject, message):
	__port = 465
	__password = 'qwerty357K!'
	__sender = 'teamozattend@gmail.com'
	#sender emails: teamozattend@gmail.com, ozattendance@gmail.com

	message = 'From: Group 2 <from@fromdomain.com>\nSubject: The alarm system has been triggered!' + str(subject) + '\n\n' + message
	try:
		with smtplib.SMTP_SSL('smtp.gmail.com', __port) as server:
			server.login(__sender, __password)
			server.sendmail(__sender, recipients, message)
			server.quit()
	except Exception as e:
		print("Error: unable to send email")
		print(e)


arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2) # Need 2s delay after declaration of arduino
arduino.write(b'51')
stream = []
j = 0

while 1:
	b = arduino.read_until(size=1)
	if b == b'3':
		if j == 0:
			print("No spam?")
			#relay(recipients = {recipients@here.place}, "Alarm system triggered", "Your alarm system has been triggered, call the cops and go home.")
			j = 1
	if b == b'4':
		# relay(recipients = {recipients@here.place}, "Alarm system disabled", "Your alarm system has been disabled.")
		print("No spam?")
arduino.close()
