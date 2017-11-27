#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char encryptForValuesInRegion(char value, char from, char to, int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    int keyDirty = atoi(argv[1]);
    int key = keyDirty % 26;

    printf("plaintext: ");
    string s = get_string();

    printf("ciphertext: ");
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        char c = s[i];

        c = encryptForValuesInRegion(c, 'A', 'Z', key);
        c = encryptForValuesInRegion(c, 'a', 'z', key);

        printf("%c", c);
    }
    printf("\n");
}

char encryptForValuesInRegion(char value, char from, char to, int key)
{
    int cn = value;
    if(value >= from && value <= to)
    {
        cn = value + key;
        if(cn > to)
        {
            cn -= 26;
        }
    }
    return (char)cn;
}