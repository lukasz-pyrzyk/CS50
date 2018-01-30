from cs50 import get_int

def printSpaces(count):
    printItem(' ', count)

def printHashes(count):
    printItem('#', count)

def printItem(character, count):
    for j in range(count):
        print(character, end='')

x = -1
while x > 23 or x < 0:
    x = get_int("Height: ")

for i in range(x):
    spaces = x - i - 1
    hashes = x - spaces

    printSpaces(spaces)
    printHashes(hashes)
    printSpaces(2)
    printHashes(hashes)
    print("")