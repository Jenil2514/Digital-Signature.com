import hashlib
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Hash import SHA256


def generate_rsa_key_pair():
    # Generate an RSA key pair
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key


def sign_message(message, private_key):
    # Create a SHA-256 hash of the message
    hash_object = hashlib.sha256(message.encode('utf-8'))
    digest = hash_object.digest()

    # Sign the digest using the RSA private key
    key = RSA.import_key(private_key)
    signer = PKCS1_v1_5.new(key)
    signature = signer.sign(digest)
    return signature


def verify_signature(message, signature, public_key):
    # Create a SHA-256 hash of the message
    hash_object = hashlib.sha256(message.encode('utf-8'))
    digest = hash_object.digest()

    # Verify the signature using the RSA public key
    key = RSA.import_key(public_key)
    verifier = PKCS1_v1_5.new(key)
    return verifier.verify(digest, signature)


def encrypt_message(message, public_key):
    # Encrypt the message using RSA public key encryption
    key = RSA.import_key(public_key)
    cipher = PKCS1_OAEP.new(key)
    encrypted_message = cipher.encrypt(message.encode('utf-8'))
    return encrypted_message


def decrypt_message(encrypted_message, private_key):
    # Decrypt the message using RSA private key decryption
    key = RSA.import_key(private_key)
    cipher = PKCS1_OAEP.new(key)
    decrypted_message = cipher.decrypt(encrypted_message)
    return decrypted_message.decode('utf-8')


# Sender's side
sender_private_key, sender_public_key = generate_rsa_key_pair()

email_message = "Hello, this is a confidential email."

# Step 1: Generate the digital signature
digital_signature = sign_message(email_message, sender_private_key)

# Step 2: Encrypt the email and digital signature
encrypted_email = encrypt_message(email_message, sender_public_key)
encrypted_signature = encrypt_message(digital_signature, sender_public_key)

# Step 3: Prepare the encrypted email
prepared_email = prepare_email(encrypted_email, encrypted_signature)

# Step 4: Send the prepared email to the recipient
send_email(prepared_email)


# Recipient's side
recipient_private_key, recipient_public_key = generate_rsa_key_pair()

encrypted_email = receive_encrypted_email()
encrypted_signature = receive_encrypted_signature()

# Step 1: Decrypt the email and digital signature
decrypted_email = decrypt_message(encrypted_email, recipient_private_key)
decrypted_signature = decrypt_message(encrypted_signature, recipient_private_key)

# Step 2: Verify the digital signature
is_verified = verify_signature(decrypted_email, decrypted_signature, sender_public_key)

if is_verified:
    print("The email is authentic.")
    print("Decrypted message:", decrypted_email)
else:
    print("The email could not be verified and may have been tampered with.")