from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA

from PyPDF2 import PdfFileReader

# Read the PDF file
file_in = open("document.pdf", "rb")
pdf_content = file_in.read()
file_in.close()

message = pdf_content

key = RSA.import_key(open('private.key').read())  # Import the private key
hash = SHA256.new(message)  # Create a hash of the PDF content

# Sign the message
signer = pkcs1_15.new(key)
signature = signer.sign(hash)

# Save signature and PDF
file_out = open("signature.pem", "wb")
file_out.write(signature)
file_out.close()

file_out = open("signed_document.pdf", "wb")
file_out.write(pdf_content)
file_out.close()
