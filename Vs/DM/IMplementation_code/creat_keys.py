from Crypto.PublicKey import RSA

# generate2048 byte key
key = RSA.generate(2048)

# write private and public key to a file
private_key = key.export_key()
file_out = open('private.key','wb')
file_out.write(private_key)
file_out.close

# public_key = key.public().export_key()
public_key = key.export_key()
file_out = open('public.key','wb')
file_out.write(public_key)
file_out.close()