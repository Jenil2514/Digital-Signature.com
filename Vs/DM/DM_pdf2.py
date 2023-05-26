import fitz

# Open the PDF file
pdf_file = "input.pdf"
doc = fitz.open(pdf_file)

# Select the page to sign
page_number = 0  # Choose the page number you want to sign (starting from 0)

# Load the private key and certificate
private_key_file = "private_key.pem"
certificate_file = "certificate.pem"

# Load the page
page = doc[page_number]

# Create a signature annotation
signature = page.add_annotation(
    "Signature",
    rect=fitz.Rect(50, 50, 150, 150),  # Specify the position and size of the signature box
    fill_color=(1, 1, 0),  # Set the fill color to yellow
    stroke_color=(0, 0, 0),  # Set the stroke color to black
)

# Set the signature properties
signature.update(
    # Specify the private key and certificate file paths
    data=f"signfile://{private_key_file}:{certificate_file}",
    # Set the reason for signing
    info={"reason": "Digitally signed using Python"},
)

# Save the modified PDF with the signature
output_file = "output.pdf"
doc.save(output_file)

# Close the PDF document
doc.close()

print("PDF signed successfully.")
