#include <stdio.h>



int main(){

    int a = 20, b = 40;
    int *ptr1 = &a;
    int *ptr2 = &b;

    if(*ptr1 > *ptr2) printf("Maximum number is: %d", *ptr1);
    else printf("Maximum number is: %d", *ptr2);


    return 0;


}
