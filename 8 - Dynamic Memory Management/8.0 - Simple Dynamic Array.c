#include <stdio.h>
#include <stdlib.h>





int main(){

    int n, i;
    int *arr;

    printf("Enter number of students: ");
    scanf("%d", &n);



    // Allocate memory for 'n' intergers
    arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed!");
        return 1;
    }

    // Input marks
    printf("Enter marks of %d students:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    //Display marks
    printf("Student marks");
    for(i = 0; i < n; i++){
        printf("%d", arr[i]);
    }


    //free memory
    free(arr);


}
