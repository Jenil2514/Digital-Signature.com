import fitz
from PIL import Image, ImageDraw, ImageFont
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import rsa
import cryptography

# Generate the signature image
def generate_signature_image(signature_text, image_width, image_height, font_path):
    # Create a new image with white background
    signature_image = Image.new("RGB", (image_width, image_height), (255, 255, 255))

    # Create a drawing object
    draw = ImageDraw.Draw(signature_image)

    # Specify the font for the signature
    font = ImageFont.truetype(font_path, size=20)

    # Calculate the position to center the text
    text_width, text_height = draw.textsize(signature_text, font=font)
    text_x = (image_width - text_width) // 2
    text_y = (image_height - text_height) // 2

    # Draw the signature text on the image
    draw.text((text_x, text_y), signature_text, font=font, fill=(0, 0, 0))

    return signature_image

# Signature image dimensions
image_width = 200
image_height = 50

# Signature text and font path
signature_text = "John Doe"
font_path = r"C:\Users\jenil\Desktop\Vs\DM\arial\arial.ttf"  # Replace with the path to your desired font file

# Generate the signature image
signature_image = generate_signature_image(signature_text, image_width, image_height, font_path)

# Save the signature image as "signature.png"
signature_img_file = "signature.png"
signature_image.save(signature_img_file)

print("Signature image generated successfully.")

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

# Add the signature image as an attachment to the PDF
page = doc[page_number]
rect = fitz.Rect(100, 100, 300, 200)  # Specify the position and size of the image annotation
annot = page.add_freetext_annot(rect, "")
annot.set_colors(stroke=(0, 0, 0), fill=(0, 0, 0))
annot.set_opacity(0.8)
annot.set_file_attachment(signature_img_file)  # Attach the signature image file to the annotation

# Save the modified PDF with the signature image
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

# Load the PDF file
pdf_file = "output.pdf"
doc = fitz.open(pdf_file)

# Select the page where the signature is located
page_number = 0  # Choose the page number where the signature is located (starting from 0)

# Retrieve the signature from the annotation
page = doc[page_number]
annotation = page.first_annot
signature_img = annotation.get_file_attachment()

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
