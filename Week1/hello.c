#include <cs50.h>
#include <stdio.h>

int main() {
    printf("Name: ");
    string name = get_string();
    printf("hello %s\n", name);
    return 0;
}