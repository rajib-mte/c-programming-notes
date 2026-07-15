#include <stdio.h>

int main()
{
    int value = 10;
    int *ptr = &value;

    printf("Size of value = %zu bytes\n", sizeof(value));
    printf("Size of pointer = %zu bytes\n", sizeof(ptr));

    //Note: Pointer size depends on the system architecture (typically 4 bytes on 32-bit systems and 8 bytes on 64-bit systems).
    return 0;
}
