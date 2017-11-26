#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{
    if(argc != 2)
    {
        printf("please provide a key");
        return 1;
    }

    int n = atoi(argv[1]);
    int key = n % 26;

    printf("Key: %i\n", key);
    printf("plaintext: ");
    string s = get_string();

    printf("ciphertext: ");
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        // TODO: 'z' => 'a' instead of '{'
        printf("%c", s[i] + key);
    }
    printf("\n");    
}