import fitz
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import rsa
import cryptography

# Load the PDF file
pdf_file = "sample.pdf"
doc = fitz.open(pdf_file)

# Select the page to sign
page_number = 0  # Choose the page number you want to sign (starting from 0)

# Convert the message to bytes
message = "Hello, this is a sample message for digital signature."
message_bytes = message.encode("utf-8")

# Hash the message using SHA-256
digest = hashes.Hash(hashes.SHA256(), backend=default_backend())
digest.update(message_bytes)
hashed_message = digest.finalize()

# Generate RSA key pair
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
    backend=default_backend()
)
public_key = private_key.public_key()

# Sign the hashed message using the private key
signature = private_key.sign(
    hashed_message,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)

# Add the signature as an annotation to the PDF
page = doc[page_number]
page_width = page.rect.width
page_height = page.rect.height
rect_width = 200
rect_height = 50
rect_x = (page_width - rect_width) / 2
rect_y = (page_height - rect_height) / 2
rect = fitz.Rect(rect_x, rect_y, rect_x + rect_width, rect_y + rect_height)
page.add_freetext_annot(rect, signature.hex(), text_color=(1, 0, 0))

# Save the modified PDF with the signature
output_file = "output.pdf"
doc.save(output_file)

# Close the PDF document
doc.close()

print("PDF signed successfully.")

# Serialize the public key to PEM format
public_key_pem = public_key.public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)

# Save the public key to a PEM file
public_key_file = "public_key.pem"
with open(public_key_file, "wb") as file:
    file.write(public_key_pem)

print("Public key PEM file generated successfully.")
