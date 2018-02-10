import sys
import crypt


def char_range(c1, c2):
    yield from range(ord(c1), ord(c2) + 1)


if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]}\n")
    sys.exit(1)


salt = sys.argv[1]
letters = [None] * 53
letters[0] = '.'
index = 1

for i in char_range('A', 'Z'):
    letters[index] = chr(i)
    index += 1

for i in char_range('a', 'z'):
    letters[index] = chr(i)
    index += 1

for i in range(53):
    for j in range(53):
        for k in range(53):
            for l in range(53):
                password = letters[l] + letters[k] + letters[j] + letters[i]
                print(f"Password: {password}")
                hash = crypt.crypt(password, salt)
                if (hash == sys.argv[1]):
                    print(suspect)
                    sys.exit(0)

print("Nothing found...\n")