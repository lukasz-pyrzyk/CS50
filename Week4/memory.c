#include <stdlib.h>

void f()
{
    int* x = malloc(10 * sizeof(int));
    //x[10] = 0; // assign 0 to the 11'th element
    x[9] = 0;
    free(x);
}

int main()
{
    f();
    return 0;
}