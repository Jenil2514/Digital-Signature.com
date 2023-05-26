from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA

from PyPDF2 import PdfFileReader

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
