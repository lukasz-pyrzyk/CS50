#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("X is: ");
    int x = get_int();

    printf("Y is: ");
    int y = get_int();

    int z = x + y;
    printf("%i plus %i is %i\n", x, y, x + y);
    printf("%i minus %i is %i\n", x, y, x - y);
    printf("%i times %i is %i\n", x, y, x * y);
    printf("%i divided by %i is %i\n", x, y, x / y);
    printf("remainder of %i divided by %i is %i\n", x, y, x % y);
}