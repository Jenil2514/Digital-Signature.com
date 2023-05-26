import fitz
import cryptography
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding

# Load the PDF file
pdf_file = "output.pdf"
doc = fitz.open(pdf_file)

# Select the page where the signature is located
page_number = 0  # Choose the page number where the signature is located (starting from 0)

# Retrieve the signature from the annotation
page = doc[page_number]
annotation = page.first_annot
signature_hex = annotation.get_text()

# Convert the signature from hexadecimal string to bytes
signature = bytes.fromhex(signature_hex)

# Convert the message to bytes
message = "Hello, this is a sample message for digital signature."
message_bytes = message.encode("utf-8")

# Hash the message using SHA-256
digest = hashes.Hash(hashes.SHA256())
digest.update(message_bytes)
hashed_message = digest.finalize()

# Load the recipient's public key
public_key_file = r"C:\Users\jenil\Desktop\Vs\DM\public_key.pem"  # Specify the path to the recipient's public key file
with open(public_key_file, "rb") as key_file:
    public_key = serialization.load_pem_public_key(key_file.read())

# Verify the signature using the public key
try:
    public_key.verify(
        signature,
        hashed_message,
        padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )
    print("Signature is valid.")
except cryptography.exceptions.InvalidSignature:
    print("Signature is invalid.")

# Close the PDF document
doc.close()
