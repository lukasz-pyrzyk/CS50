from cs50 import get_int

x = -1
# get value from the user
while x > 23 or x < 0:
    x = get_int("Height: ")

# print the stairs
for i in range(x):
    spaces = x - i - 1
    hashes = x - spaces

    print(" " * spaces, end="")
    print("#" * hashes, end="")
    print(" " * 2, end="")
    print("#" * hashes, end="")
    print("")