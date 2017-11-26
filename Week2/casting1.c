#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main() 
{
    for (char i = 'A'; i < 'Z'; i++)
    {
        printf("%c is %i\n", i, i);
    }
}