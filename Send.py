import smtplib
import ssl

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
