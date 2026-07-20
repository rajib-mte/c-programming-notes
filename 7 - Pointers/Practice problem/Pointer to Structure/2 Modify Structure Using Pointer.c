#include <stdio.h>



struct Device{

    int id;
    float voltage;

};

int main(){

    struct Device d1 = {1, 3.3};

    struct Device *ptr = &d1;

    ptr->voltage = 5.5;

    printf("ID = %d\n", ptr->id);
    printf("Voltage = %.1fV", ptr->voltage);


    return 0;



}
