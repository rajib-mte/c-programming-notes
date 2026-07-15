#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(sizeof(int));

    if(ptr != NULL)
    {
        *ptr = 50;

        printf("Value = %d", *ptr);

        free(ptr);
    }

    return 0;
}
