#include <stdio.h>
#include <cs50.h>

int square(int x);

int main()
{
    printf("x is: ");
    int x = get_int();
    printf("x^2 is %i\n", square(x));
}

int square(int x)
{
    return x * x;
}