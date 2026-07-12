#include <stdio.h>

int main(void)
{
    int number = 10;

    int *ptr = &number;

    printf("number      = %d\n", number);
    printf("&number     = %p\n", (void *)&number);

    printf("ptr         = %p\n", (void *)ptr);
    printf("*ptr        = %d\n", *ptr);

    return 0;
}