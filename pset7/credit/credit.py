from cs50 import get_int

def get_length(number):
    count = 1
    while number > 9:
        number = number / 10
        count += 1
    return count

def get_value_of(number, index):
    mod = pow(10, index + 1)
    div = pow(10, index)

    n = number % mod / div
    n = int(n)
    # print(f"Getting index {index} from {number}, result {n}")
    return n

def get_sum_of_the_even_numbers(number, length):
    sum = 0
    i = 0
    while i < length:
        n = get_value_of(number, i)
        # print(f"Index {15 - i} has value {n}")
        sum += n
        i += 2
    return sum

def get_sum_of_the_odd_numbers(number, length):
    sum = 0
    i = 1
    while i < length:
        n = get_value_of(number, i)
        multiplied = n * 2
        # print(f"n is {n}, *2 is {multiplied}")
        if multiplied >= 10:
            value = get_value_of(multiplied, 0) + get_value_of(multiplied, 1)
            sum += value
        else:
            sum += multiplied
        i += 2
    return sum

def Validate(evenSum, oddSum):
    return (evenSum + oddSum) % 10 == 0

def get_producer(n):
    if (n >= 340000000000000 and n < 350000000000000) or (n >= 370000000000000 and n < 380000000000000):
        return "AMEX"
    elif (n >= 5100000000000000 and n < 5600000000000000):
        return "MASTERCARD"
    elif ((n >= 4000000000000 and n < 5000000000000) or (n >= 4000000000000000 and n < 5000000000000000)):
        return "VISA"
    else:
        return "INVALID"

number = -1
while number < 0:
    number = get_int("Card number: ")

length = get_length(number)
evenSum = get_sum_of_the_even_numbers(number, length)
# print(f"Sum of even numbers is {evenSum}")

oddSum = get_sum_of_the_odd_numbers(number, length)
# print(f"Sum of odd numbers is {oddSum}")
numberIsValid = Validate(evenSum, oddSum)

if numberIsValid:
    producer = get_producer(number)
    print(producer)
else:
    print("INVALID")