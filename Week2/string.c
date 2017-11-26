#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main() 
{
    string s = get_string();
    if(s == NULL)
    {
        printf("error");
    }
    else
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c", s[i]);
        }
    }
}