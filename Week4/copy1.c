#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    printf("s: ");
    char* s = get_string();

    if(s == NULL)
    {
        return 1;
    }

    char* t = malloc((strlen(s) + 1) * sizeof(char));
    if(t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}