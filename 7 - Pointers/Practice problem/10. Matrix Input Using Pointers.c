#include <stdio.h>




int main(){


    int matrix[2][2];
    int (*ptr)[2] = matrix;
    int size = sizeof(matrix) / sizeof(matrix[0][0]);

    printf("Enter matrix elements:\n");

    for(int i = 0; i < size; i++){
        scanf("%d", ptr + i);
    }

    printf("Matrix:\n");

    for(int i = 0; i < size; i++){
        printf("%d ", *(ptr + i));
    }

    return 0;

}
