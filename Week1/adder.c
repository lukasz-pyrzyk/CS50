#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("X is: ");
    int x = get_int();

    printf("Y is: ");
    int y = get_int();

    int z = x + y;
    printf("Sum: %i\n", z);
}