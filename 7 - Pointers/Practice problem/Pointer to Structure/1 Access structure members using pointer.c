#include <stdio.h>


struct Student{
    int id;
    float marks;
};


int main(){

    struct Student s1 = {10, 85.6};
    struct Student *ptr = &s1;


    printf("Student id: %d\n", ptr->id);
    printf("Marks number: %.2f\n", ptr->marks);

    return 0;
}
