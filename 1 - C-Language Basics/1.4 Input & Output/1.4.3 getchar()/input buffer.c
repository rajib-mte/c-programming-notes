#include <stdio.h>




int main(){

//    char ch1;
//    char ch2;
//
//    ch1 = getchar();
//    ch2 = getchar();
//
//    printf("ch1: %c\n", ch1);
//    printf("ch2: %c\n", ch2);

    int age;
    char grade;


    scanf("%d", &age);

//    while(getchar() != '\n'){
//        printf("please enter your character\n");
//    }
    while (grade != '\n') {
        printf("please enter your character\n");
         grade = getchar();
    }

//    grade = getchar();

    printf("%c", grade);


    return 0;

}
