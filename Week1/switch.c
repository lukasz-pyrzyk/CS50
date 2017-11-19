#include <stdio.h>
#include <cs50.h>

int main()
{
    char c = get_char();

    switch (c)
    {
        case 'Y':
        case 'y':
            printf("yes");
            break;
        
        case 'N':
        case 'n':
            printf("no");
            break;

        default:
            printf("error");
            break;
    }
}