#include <stdio.h>





int main(){

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *start = arr;
    int *end = arr + size - 1;

    if(start < end){
        int temp;
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
