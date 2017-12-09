#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }

    char salt[2];
    strncpy(salt, argv[1], 2);

    char letters[53];
    letters[0] = '\0';
    int index = 1;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        letters[index++] = i;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        letters[index++] = i;
    }

    char suspect[5];
    for(int i = 0; i < 53; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            for (int k = 0; k < 53; k++)
            {
                for (int l = 1; l < 53; l++)
                {
                    suspect[0] = letters[l];
                    suspect[1] = letters[k];
                    suspect[2] = letters[j];
                    suspect[3] = letters[i];

                    string hash = crypt(suspect, salt);
                    if (strcmp(hash, argv[1]) == 0)
                    {
                        printf("%s\n", suspect);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Nothing found...\n");
}