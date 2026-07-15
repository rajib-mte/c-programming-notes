#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 10; i++)
    {
        printf("\rCount: %d", i);

        // Delay only for demonstration
        for (volatile long j = 0; j < 300000000; j++);
    }

    printf("\n");
    return 0;
}
