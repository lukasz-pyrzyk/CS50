#include <stdio.h>
#include <cs50.h>
#include <math.h>

float roundNumber(float n);

int main()
{
    float x;
    do
    {
        printf("Change: ");
        x = get_float();
    }
    while (x < 0);

    float coints[] = {0.25, 0.1, 0.05, 0.01};
    int count = 0;
    int i = 0;
    while (i < 4)
    {
        float coin = coints[i];
        float value = roundNumber(x);
        if (value >= coin)
        {
            x -= coin;
            count++;
            printf("Using %f\n", coin);
        }
        else
        {
            printf("Cannot use %f, current value is %f\n", coin, value);
            i++;
        }
    }

    printf("%i\n", count);
}

float roundNumber(float n)
{
    return roundf(n * 100) / 100;
}