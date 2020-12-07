import smtplib
import ssl

#recipients is a list of emails
def relay(recipients, subject, message):
	__port = 465
	__password = 'qwerty357K!'
	__sender = 'teamozattend@gmail.com'
	#sender emails: teamozattend@gmail.com, ozattendance@gmail.com
	
	message = 'From: Group 2 <from@fromdomain.com>\nSubject: ' + str(subject) + '\n\n' + message
	try:
		with smtplib.SMTP_SSL('smtp.gmail.com', __port) as server:
			server.login(__sender, __password)
			server.sendmail(__sender, recipients, message)
			server.quit()
	except Exception as e:
		print("Error: unable to send email")
		print(e)

# Wake for Arduino
arduino = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2) # Need 2s delay after declaration of arduino
arduino.write(b'51')

# Stings
trip = "Your alarm system has been triggered.\nYou may wish to call the cops."
dis = "Your alarm system has been disabled.\n"

while 1:
	b = arduino.read_until(size=1)
	if b == b'3':
		print("No spam?")
		# relay([recipients@here.place], "Alarm system triggered", trip)
	else if b == b'4':
		# relay([recipients@here.place], "Alarm system disabled", dis)
		print("No spam?")


arduino.close()