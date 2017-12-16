#include <cs50.h>
#include <stdio.h>

int main()
{
    printf("s: ");
    string s = get_string();

    printf("s: ");
    string t = get_string();

    if (s == t)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }

}