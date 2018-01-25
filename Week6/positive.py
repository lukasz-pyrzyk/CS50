from cs50 import get_int

def main():
    i = get_positve_int("Positive int, please ")
    print(i)

def get_positve_int(prompt):
    while True:
        n = get_int(prompt)
        if n >= 1:
            break
    return n

if __name__ == "__main__":
    main()