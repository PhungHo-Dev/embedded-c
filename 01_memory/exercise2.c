#include <stdio.h>

int *foo(void)
{
    int local = 100;

    return &local;
}

void bar(void)
{
    int x = 999;
    printf("bar: %d\n", x);
}

int main(void)
{
    int *ptr = foo();

    bar();

    printf("%d\n", *ptr);

    return 0;
}