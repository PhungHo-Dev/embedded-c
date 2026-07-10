#include <stdio.h>
#include <stdlib.h>

int global_init = 100;
int global_uninit;

void foo(void)
{
    int local = 10;
    static int counter = 0;

    int *heap = malloc(sizeof(int));

    *heap = 20;

    printf("global_init    : %p\n",(void*)&global_init);
    printf("global_uninit  : %p\n",(void*)&global_uninit);
    printf("local          : %p\n",(void*)&local);
    printf("counter        : %p\n",(void*)&counter);
    printf("heap           : %p\n",(void*)heap);

    free(heap);
}

int main(void)
{
    foo();

    return 0;
}