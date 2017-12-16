#include <stdio.h>
#include <cs50.h>

void swap (int* a, int* b);

int main()
{
    int a = get_int();
    int b = get_int();

    swap(&a, &b);

    printf("a changed to %i, b: %i\n", a, b);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}