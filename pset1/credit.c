#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_length(long long number);
int get_sum_of_the_even_numbers(long long number, int length);
int get_sum_of_the_odd_numbers(long long number, int length);
int get_value_of(long long number, int index);
bool Validate(int evenSum, int oddSum);
string get_producer(long long number);

int main()
{
    long long number = 0;
    do
    {
        printf("Card number: ");
        number = get_long_long();
    }
    while (number < 0);

    int length = get_length(number);
    int evenSum = get_sum_of_the_even_numbers(number, length);
    int oddSum = get_sum_of_the_odd_numbers(number, length);

    //printf("Sum of even numbers is %i\n", evenSum);
    //printf("Sum of odd numbers is %i\n", oddSum);
    bool numberIsValid = Validate(evenSum, oddSum);

    if(numberIsValid)
    {
        string producer = get_producer(number);
        printf("%s", producer);
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_length(long long number)
{
    int count = 1;
    while (number > 9)
    {
        number = number / 10;
        count++;
    }
    return count;
}

int get_value_of(long long number, int index)
{
    long long mod = powf(10, index + 1);
    long long div = powf(10, index);

    int n = number % mod / div;
    //printf("Using mod %lld and div %lld, result %i\n", mod, div, n);
    return n;
}

int get_sum_of_the_even_numbers(long long number, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i += 2)
    {
        int n = get_value_of(number, i);
        //printf("Index %i has value %i\n", 15 - i, n);
        sum += n;
    }
    return sum;
}

int get_sum_of_the_odd_numbers(long long number, int length)
{
    int sum = 0;
    for (int i = 1; i < length; i += 2)
    {
        int n = get_value_of(number, i);
        int multiplied = n * 2;
        //printf("n is %i, *2 is %i\n", n, multiplied);
        if(multiplied > 10)
        {
            int value = get_value_of(multiplied, 0) + get_value_of(multiplied, 1);
            sum += value;
        }
        else
        {
            sum += multiplied;
        }
    }
    return sum;
}

bool Validate(int evenSum, int oddSum)
{
    return (evenSum + oddSum) % 10 == 0;
}

string get_producer(long long n)
{
    if ((n >= 340000000000000 && n < 350000000000000) || (n >= 370000000000000 && n < 380000000000000))
        return "AMEX\n";
    else if (n >= 5100000000000000 && n < 5600000000000000)
        return "MASTERCARD\n";
    else if ((n >= 4000000000000 && n < 5000000000000) || (n >= 4000000000000000 && n < 5000000000000000))
        return "VISA\n";
    else
        return "INVALID\n";
}