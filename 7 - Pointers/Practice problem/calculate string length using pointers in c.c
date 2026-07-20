#include <stdio.h>



int string_length(char *ptr){

    int length = 0;

    while(*ptr != '\0'){
        length++;
        ptr++;
    }

    return length;

}


int main(){

    char str[] = "hello";

    printf("String length: %d", string_length(str));



}
