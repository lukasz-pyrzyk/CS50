import sys
from cs50 import get_string

book = [
    "X",
    "Y"
]

name = get_string("name: ")
if name in book:
    print(f"Calling {name}")
