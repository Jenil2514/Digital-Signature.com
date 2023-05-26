import hashlib
from pypdf2rsa import PdfFileReader, PdfFileWriter
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes

def generate_key_pair():
    from cryptography.hazmat.primitives.asymmetric import rsa

    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=2048
    )

    private_pem = private_key.private_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PrivateFormat.PKCS8,
        encryption_algorithm=serialization.NoEncryption()
    )

    public_key = private_key.public_key()
    public_pem = public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )

    return private_pem, public_pem

def sign_pdf_file(pdf_file_path, private_key_path, signed_pdf_path):
    with open(pdf_file_path, 'rb') as file:
        pdf_content = file.read()

    private_key = serialization.load_pem_private_key(
        open(private_key_path, "rb").read(),
        password=None
    )

    hasher = hashlib.sha256()
    hasher.update(pdf_content)
    hash_value = hasher.digest()

    signature = private_key.sign(
        hash_value,
        padding.PKCS1v15(),
        hashes.SHA256()
    )

    output_pdf = PdfFileWriter()
    input_pdf = PdfFileReader(open(pdf_file_path, 'rb'))

    input_pdf.Info.Title = '/Signature'
    input_pdf.Info.Signature = signature

    for page in input_pdf.pages:
        output_pdf.add_page(page)

    with open(signed_pdf_path, 'wb') as file:
        output_pdf.write(file)

def verify_signed_pdf(pdf_file_path, public_key_path):
    with open(pdf_file_path, 'rb') as file:
        pdf_content = file.read()

    pdf_reader = PdfFileReader(open(pdf_file_path, 'rb'))
    signature = pdf_reader.Info.get('/Signature')

    public_key = serialization.load_pem_public_key(
        open(public_key_path, "rb").read()
    )

    hasher = hashlib.sha256()
    hasher.update(pdf_content)
    hash_value = hasher.digest()

    try:
        public_key.verify(
            signature,
            hash_value,
            padding.PKCS1v15(),
            hashes.SHA256()
        )
        return True
    except Exception:
        return False

# Example usage
private_key, public_key = generate_key_pair()
with open('private_key.pem', 'wb') as file:
    file.write(private_key)
with open('public_key.pem', 'wb') as file:
    file.write(public_key)

pdf_file_path = 'document.pdf'
signed_pdf_path = 'signed_document.pdf'

sign_pdf_file(pdf_file_path, 'private_key.pem', signed_pdf_path)
is_verified = verify_signed_pdf(signed_pdf_path, 'public_key.pem')
print(f"Signature verification result: {is_verified}")
