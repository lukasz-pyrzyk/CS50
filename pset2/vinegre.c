#include <stdio.h>
#include <cs50.h>
#include <string.h>

int getKey(string hasher, int index);
char shiftValue(char input, char min, char max, int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    string key = argv[1];

    printf("plaintext: ");
    string s = get_string();

    printf("ciphertext: ");
    int index = 0;
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        int currentKey = getKey(key, index);
        char original = s[i];
        char encrypted = original;

        if ('A' <= original && original <= 'Z')
        {
            encrypted = shiftValue(encrypted, 'A', 'Z', currentKey);
            index++;
        }
        else if ('a' <= original && original <= 'z')
        {
            encrypted = shiftValue(encrypted, 'a', 'z', currentKey);
            index++;
        }

       printf("%c", encrypted);
    }
    printf("\n");
}

int getKey(string hasher, int index)
{
    int length = strlen(hasher);
    char character = hasher[index % length];
    
    if('A' <= character && character <= 'Z')
    {
        return character - 'A';
    }
    else 
    {
        return character - 'a';
    }
}

char shiftValue(char input, char min, char max, int key)
{
    if (min <= input && input <= max)
    {
        int crypted = input + key;
        if (crypted > max)
        {
            crypted -= 26;
        }
        
        // printf("%c changed to %c using key %i (%c)\n", input, crypted, key, key + 'A');
        return (char)crypted;
    }

    return input;
}