#include <stdio.h>
#include <cs50.h>

void printSpaces(int count);
void printHashes(int count);
void print(char character, int count);
void finishLine();

int main()
{
    int x = -1;
    while (x > 23 || x < 0)
    {
        printf("Height: ");
        x = get_int();
    }

    for (int i = 0; i < x; i++)
    {
        int spaces = x - i - 1;
        int hashes = x - spaces + 1;

        printSpaces(spaces);
        printHashes(hashes);
        finishLine();
    }
}

void printSpaces(int count)
{
    print(' ', count);
}

void printHashes(int count)
{
    print('#', count);
}

void print(char character, int count)
{
    for (int j = 0; j < count; j++)
    {
        printf("%c", character);
    }
}

void finishLine()
{
    printf("\n");
}