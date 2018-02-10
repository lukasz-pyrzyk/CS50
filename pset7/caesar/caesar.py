import sys
from cs50 import get_string


def encryptForValuesInRegion(value, beginning, to, key):
    cn = ord(value)
    if value >= beginning and value <= to:
        cn += key
        if cn > ord(to):
            cn -= 26
    return chr(cn)


if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]}\n")
    sys.exit(1)

keyDirty = int(sys.argv[1])
key = keyDirty % 26

s = get_string("plaintext: ")

print("ciphertext: ")
for i in range(len(s)):
    c = s[i]
    c = encryptForValuesInRegion(c, 'A', 'Z', key)
    c = encryptForValuesInRegion(c, 'a', 'z', key)

    print(c, end="")
print("")