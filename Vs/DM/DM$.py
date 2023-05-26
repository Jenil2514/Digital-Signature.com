import smtplib
from email.mime.text import MIMEText

smtp_server = "smtp.gmail.com"
smtp_port = 465
sender_email = "jenilgoswami65@gmail.com"
sender_password = "J_enil@283924"
recipient_email = "kathanakadiya@gmail.com"
message = "Hello, this is a sample email."

# Create the email message
email_message = MIMEText(message)
email_message["Subject"] = "Test Email"
email_message["From"] = sender_email
email_message["To"] = recipient_email

# Connect to the SMTP server
with smtplib.SMTP_SSL(smtp_server, smtp_port) as server:
    # Login to your Gmail account
    server.login("jenilgoswami65@gmail.com", "J_enil@283924")
    # Send the email
    server.send_message(email_message)

print("Email sent successfully.")
