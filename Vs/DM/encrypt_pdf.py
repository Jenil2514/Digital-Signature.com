from PyPDF2 import PdfReader
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes

def find_signature(pdf_reader):
    # Search for the signature in different possible locations within the PDF structure
    possible_keys = ['/AcroForm/Fields', '/SigFlags', '/Type/Sig', '/Type/Annot']
    for key in possible_keys:
        try:
            signature = pdf_reader.trailer.raw_get(key).getObject()
            return signature
        except KeyError:
            continue
    return None

def verify_signed_pdf(signed_pdf_path, public_key_path, output_path):
    with open(signed_pdf_path, 'rb') as file:
        signed_pdf_content = file.read()

    pdf_reader = PdfReader(open(signed_pdf_path, 'rb'))
    signature = find_signature(pdf_reader)

    if signature is None:
        return False

    public_key = serialization.load_pem_public_key(
        open(public_key_path, "rb").read()
    )

    try:
        public_key.verify(
            signature,
            signed_pdf_content,
            padding.PKCS1v15(),
            hashes.SHA256()
        )
        # Signature verification successful, extract original content
        original_pdf_content = pdf_reader.pages[0].extract_text()
        with open(output_path, 'w', encoding='utf-8') as file:
            file.write(original_pdf_content)
        return True
    except Exception:
        return False

# Example usage
public_key_path = 'public_key.pem'
signed_pdf_path = 'output.pdf'
output_path = '.pdf'

is_verified = verify_signed_pdf(signed_pdf_path, public_key_path, output_path)
if is_verified:
    print("Signature verification failed.")
else:
    print(f"Signature verification successful. Extracted original content to '{output_path}'.")
