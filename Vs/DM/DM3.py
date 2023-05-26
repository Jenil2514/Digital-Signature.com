import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.utils import formatdate
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import rsa

# Generate RSA key pair for the sender
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
    backend=default_backend()
)
public_key = private_key.public_key()

# Convert the message to bytes
message = "Hello, this is a sample email message."
message_bytes = message.encode("utf-8")

# Hash the message
hash_value = hashes.Hash(hashes.SHA256(), backend=default_backend())
hash_value.update(message_bytes)
digest = hash_value.finalize()

# Sign the digest using the sender's private key
signature = private_key.sign(
    digest,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)

# Create the email message
email_message = MIMEMultipart()
email_message["From"] = "jenilgoswami65@gmail.com"
email_message["To"] = "kathanakadiya@gmail.com"
email_message["Subject"] = "Signed Email"
email_message["Date"] = formatdate(localtime=True)

# Attach the message body
email_message.attach(MIMEText(message, "plain"))

# Attach the digital signature as an attachment
signature_attachment = MIMEApplication(signature)
signature_attachment.add_header("Content-Disposition", "attachment", filename="signature.bin")
email_message.attach(signature_attachment)

# Connect to the SMTP server and send the email
smtp_server = "smtp.gmail.com"
smtp_port = 465
sender_email = "jenilgoswami65@gmail.com"
sender_password = "J_enil@283924"

with smtplib.SMTP(smtp_server, smtp_port) as server:
    server.starttls()
    server.login("jenilgoswami65@gmail.com","J_enil@283924")
    server.send_message(email_message)

print("Email sent successfully.")
