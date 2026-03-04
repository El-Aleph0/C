//Function to find the maximum element in an array
#include <stdio.h>

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}
int main() {
    int i;

    for(i = 0; i < 10; i++) {
        printf("2^%d = %d\n", i, power(2, i));
    }

    //Accept user input
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    printf("%d^%d = %d\n", base, exp, power(base, exp));
                
    return 0;
}