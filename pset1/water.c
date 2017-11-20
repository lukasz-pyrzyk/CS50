#include <stdio.h>
#include <cs50.h>

int main()
{
    printf("How many minutes? ");
    printf("\n");
    int minutes = get_int();
    printf("Minutes: %i\n", minutes);
    printf("Bottles: %i\n", minutes * 12);
}