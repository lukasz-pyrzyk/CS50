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
        char crypted = original;

        if ('A' <= original && original <= 'Z')
        {
            crypted = shiftValue(crypted, 'A', 'Z', currentKey);
            index++;
        }
        else if ('a' <= original && original <= 'z')
        {
            crypted = shiftValue(crypted, 'a', 'z', currentKey);
            index++;
        }

       printf("%c", crypted);
    }
    printf("\n");
}

int getKey(string hasher, int index)
{
    int length = strlen(hasher);
    char character = hasher[index % length];
    int key = 0;
    if('A' <= character && character <= 'Z')
    {
        key = character - 'A';
    }
    else 
    {
        key = character - 'a';
    }
    //printf("Char %c has value %i\n", hasher[index % length], key);
    return key;
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