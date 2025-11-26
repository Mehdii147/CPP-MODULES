#include "libc.h"

int main()
{
    int a = 5;
    int i = 0;

    while (a > 0)
    {
        i++;
        a--;
    }
    printf("Value of i: %d\n", i);
    return 0;
}