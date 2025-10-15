import hashlib


def find_secret(signature, data, append, secret_candidates):
    """
    Brute-force search for the secret.
    """
    for secret in secret_candidates:
        message = secret + data + append
        md5 = hashlib.md5()
        md5.update(message.encode())
        computed_signature = md5.hexdigest()
        if computed_signature == signature:
            return secret
    return None


# Inputs
signature = "f48b9e0018174137fa6660e8c7b9cef4"
data = "My full name is S. Charan Ganesh"
append = "SE21UCSE041"
secret_candidates = ["Hello, World!. This is a demonstration of message extension attacks. SE21UCSE001",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE002",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE003",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE004",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE005",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE006",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE007",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE008",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE009",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE010",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE011",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE012",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE013",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE014",
                     "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE041",
                     ]


found_secret = find_secret(signature, data, append, secret_candidates)


if found_secret:
    print(f"Found secret: {found_secret}")
else:
    print("Secret not found in candidates.")
