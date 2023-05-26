import random
import math

def gcd(a, b):
    # Euclidean algorithm to find the greatest common divisor
    while b != 0:
        a, b = b, a % b
    return a

def extended_gcd(a, b):
    # Extended Euclidean algorithm to find the multiplicative inverse
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = extended_gcd(b % a, a)
        return gcd, y - (b // a) * x, x
    
# Example usage
message = 90
print("Message : ",message)

def generate_keys():
    # Key generation
    p = generate_prime()
    print("p : ",p)
    q = generate_prime()
    print("q : ",q)
    n = p * q
    print("n : ",n)
    phi = (p - 1) * (q - 1)
    print("Phi : ",phi)

    # Choose a public exponent e
    e = random.randint(2, phi)
    while gcd(e, phi) != 1:
        e = random.randint(2, phi)

    # Calculate the private exponent d
    _, d, _ = extended_gcd(e, phi)
    d = d % phi
    if d < 0:
        d += phi

    # Return public and private keys
    public_key = (e, n)
    private_key = (d, n)
    return public_key, private_key

def generate_prime():
    # Generate a prime number
    while True:
        num = random.randint(2**15, 2**16)
        if is_prime(num):
            return num

def is_prime(num):
    # Check if a number is prime
    if num < 2:
        return False
    for i in range(2, math.isqrt(num) + 1):
        if num % i == 0:
            return False
    return True

def encrypt(message, public_key):
    # Encryption
    e, n = public_key
    ciphertext = pow(message, e, n)
    return ciphertext

def decrypt(ciphertext, private_key):
    # Decryption
    d, n = private_key
    message = pow(ciphertext, d, n)
    return message



# Generate keys
public_key, private_key = generate_keys()

# Encrypt the message
ciphertext = encrypt(message, public_key)
print("Ciphertext:", ciphertext)

# Decrypt the ciphertext
decrypted_message = decrypt(ciphertext, private_key)
print("Decrypted message:", decrypted_message)
