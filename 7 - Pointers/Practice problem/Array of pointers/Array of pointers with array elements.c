#include <stdio.h>



int main(){

    int number[] = {100, 200, 300, 40};
    int *ptr = number;



    for(int i = 0; i < 4; i++){
        printf("%d\n", ptr[i]);
    }

    return 0;

}
