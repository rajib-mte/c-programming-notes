#include <stdio.h>

//Function to swap to numbers using pointers
void swap(int *a, int *b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}

int main(){

    int x = 10, y = 20;


    printf("Before swapping: \n");
    printf("x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("\nAfter swapping: \n");
    printf("x = %d, y = %d", x, y);


    return 0;




}
