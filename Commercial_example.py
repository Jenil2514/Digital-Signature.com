from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA

from PyPDF2 import PdfFileReader

# generate2048 byte key
key = RSA.generate(2048)

# write private and public key to a file
private_key = key.export_key()
file_out = open('private.key','wb')
file_out.write(private_key)
file_out.close

# public_key = key.public().export_key()
public_key = key.export_key()
file_out = open('public.key','wb')
file_out.write(public_key)
print('public key successfully generated!!')
file_out.close()

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

print('signed file successfully generated!!')

# Read the public key
key = RSA.import_key(open('public.key').read())

# Read the received message and the received signature
file_in = open("document.pdf", "rb")
pdf_content = file_in.read()
file_in.close()

file_in = open("signature.pem", "rb")
signature = file_in.read()
file_in.close()

hash2 = SHA256.new(pdf_content)

try:
    pkcs1_15.new(key).verify(hash2, signature)
    print("The signature is valid. The document has not been changed.")
except (ValueError, TypeError):
    print("This is not the original document!!!!!")