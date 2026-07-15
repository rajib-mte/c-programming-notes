#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(sizeof(int));

    *ptr = 100;

    printf("Before free: %d\n", *ptr);

    free(ptr);

    printf("After free: %d\n", *ptr);

    return 0;
}
