#include <stdio.h>

void counter(void)
{
    int normal = 0;
    static int persistent = 0;

    normal++;
    persistent++;

    printf("normal     = %d\n", normal);
    printf("persistent = %d\n\n", persistent);
}

int main(void)
{
    counter();
    counter();
    counter();

    return 0;
}