from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import rsa

# Sender's Work

# Generate RSA key pair for the sender
sender_private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
    backend=default_backend()
)
sender_public_key = sender_private_key.public_key()

# Convert the message to bytes
message = "Hello, this is a sample message for digital signature."
message_bytes = message.encode("utf-8")

# Hash the message
hash_value = hashes.Hash(hashes.SHA256(), backend=default_backend())
hash_value.update(message_bytes)
digest = hash_value.finalize()

# Sign the digest using the sender's private key
signature = sender_private_key.sign(
    digest,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)

# Print the signature
print("Sender's Signature:", signature.hex())

# Receiver's Work

# Assume the receiver has the sender's public key
receiver_public_key = sender_public_key

# Verify the signature using the receiver's public key
try:
    receiver_public_key.verify(
        signature,
        digest,
        padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )
    print("Signature is valid. Message integrity and authenticity are verified.")
except:
    print("Signature is invalid. Message integrity and authenticity cannot be guaranteed.")
