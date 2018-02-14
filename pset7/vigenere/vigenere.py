import sys
from cs50 import get_string

def getKey(key, index):
    length = len(key)
    character = key[index % length]

    if 'A' <= character and character <= 'Z':
        return chr(ord(character) - ord('A'))
    else:
        return chr(ord(character) - ord('a'))

def validateKey(key):
    l = len(key)
    for i in range(l):
        c = key[i]
        if (c < 'A' or c > 'z' or (c > 'Z' and c < 'a')):
            return 1

    return 0

def shiftValue(input, max, key):
    encrypted = ord(input) + ord(key)
    if encrypted > ord(max):
        encrypted -= 26

    return chr(encrypted)

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]}\n")
    sys.exit(1)

key = sys.argv[1]
validation = validateKey(key)
if validation != 0:
    sys.exit(validation)

s = get_string("plaintext: ")
print("ciphertext: ", end="")
index = 0
l = len(s)
for i in range(l):
    currentKey = getKey(key, index)
    original = s[i]
    encrypted = original

    if ('A' <= original and original <= 'Z'):
        encrypted = shiftValue(encrypted, 'Z', currentKey)
        index += 1
    elif ('a' <= original and original <= 'z'):
        encrypted = shiftValue(encrypted, 'z', currentKey)
        index += 1

    print(encrypted, end="")

print("")