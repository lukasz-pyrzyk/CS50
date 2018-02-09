from cs50 import get_float

def roundNumber(n):
    return round(n * 100) / 100

x = -1
while x < 0:
    x = get_float("Change: ")

coints = [0.25, 0.1, 0.05, 0.01]
count = 0
i = 0
while i < 4:
    coin = coints[i]
    value = roundNumber(x)
    if value >= coin:
        x -= coin
        count += 1
        # print(f"Using {coin}")
    else:
        # print(f"Cannot use {coin}, current value is {value}")
        i += 1

print(count)