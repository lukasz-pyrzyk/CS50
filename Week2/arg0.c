#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if(argc == 2)
    {
        printf("%s\n", argv[0]);
        printf("Hello, %s\n", argv[1]);
    }
    else{
        printf("hello, world\n");
    }
}