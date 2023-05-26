from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import rsa

# Generate RSA key pair
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
    backend=default_backend()
)
print("Privatekey : ",private_key)
public_key = private_key.public_key()
print("\n")
print("Public Key : ",public_key)
print("\n")
# Convert the message to bytes
message = "This is the Text example For Digital Signature : "
message_bytes = message.encode("utf-8")

# Hash the message
hash_value = hashes.Hash(hashes.SHA256(), backend=default_backend())
hash_value.update(message_bytes)
digest = hash_value.finalize()
print("Digested : ",digest)
# Sign the digest using the private key
signature = private_key.sign(
    digest,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)

# Print the signature
print("\nSignature : ", signature.hex())

# Verify the signature using the public key
try:
    public_key.verify(
        signature,
        digest,
        padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )
    print("Signature is valid.")
except:
    print("Signature is invalid.")
