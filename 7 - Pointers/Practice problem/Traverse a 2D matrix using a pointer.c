#include <stdio.h>




int main(){

    int matrix[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };


    int *ptr = &matrix[0][0];

    int rows = 2;
    int cols = 3;


    printf("Matrix elements: \n");

    for(int i = 0; i < rows * cols; i++){
        printf("%d ", *(ptr + i));
    }


    return 0;


}
