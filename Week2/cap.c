#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main() 
{
    string s = get_string();
    if(s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            char c = s[i];
            printf("%c", toupper(c));
        }
    }
    printf("\n");
}