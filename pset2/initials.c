#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    string s = get_string();
    int n = strlen(s);

    char previous = ' ';
    for (int i = 0; i < n; i++)
    {
        char current = s[i];
        if (previous == ' ' && current >= 'A' && current <= 'z')
        {
            printf("%c", toupper(current));
        }
        previous = current;
    }

    printf("\n");
}