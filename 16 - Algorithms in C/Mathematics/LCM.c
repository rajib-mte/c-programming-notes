#include <stdio.h>



int gcd(int a, int b){

    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int main(){

    int a, b, lcm;
    scanf("%d %d", &a, &b);

    lcm = (a * b) / gcd(a, b);

    printf("LCM of %d and %d is: %d\n", a, b, lcm);

    return 0;
}
