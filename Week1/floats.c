#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("X is: ");
    float x = get_int();

    printf("Y is: ");
    float y = get_int();

    int z = x + y;
    printf("%f plus %f is %f\n", x, y, x + y);
    printf("%f minus %f is %f\n", x, y, x - y);
    printf("%f times %f is %f\n", x, y, x * y);
    printf("%f divided by %f is %f\n", x, y, x / y);

}