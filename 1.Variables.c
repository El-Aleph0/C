#include <stdio.h> // include standard input-output header file

/*Print table of Fahrenheit - Celsius*/
#define LOWER 0 // lower limit of temperature table

int main() // main function
{

    printf("%d",LOWER);
    printf("%d", sizeof(LOWER));
    printf("Type of LOWER: int, size: %zu bytes\n", sizeof(LOWER));
    
 int fahr, celsius;
 int lower, upper, step;
 lower = 0; // lower limit of temperature table
 upper = 300; // upper limit of temperature table
 step = 20; // step size

    printf("Fahrenheit to Celsius Table\n");
    fahr = lower;
    while (fahr <= upper) { // loop from lower to upper limit
        celsius = 5 * (fahr - 32) / 9; // convert Fahrenheit to Celsius
        printf("%3d %6d\n", fahr, celsius); // print Fahrenheit and Celsius values 3&6 are width specifiers
        fahr = fahr + step; // increment Fahrenheit value by step size  
    }
    float fahr1 = 0.0; // reset fahr to lower limit
    float celsius1; // declare celsius as float
    float lower1 = 0.0; // lower limit of temperature table
    float upper1 = 300.0; // upper limit of temperature table
    float step1 = 20.0; // step size
    while (fahr1 <= upper1) { // loop from lower to upper limit
        celsius1 = 5.0 * (fahr1 - 32.0) / 9.0; // convert Fahrenheit to Celsius
        printf("%3.1f %6.2f\n", fahr1, celsius1);//d is for integer values among %f for float and %c for char
        //3.1f means 3 characters wide with 1 digit after decimal for fahr1
        //6.2f means 6 characters wide with 2 digits after decimal for celsius1
        fahr1 = fahr1 + step1; // increment Fahrenheit value by step size  
    }
    /*Exercise now make the conversion from Celsius to Fahrenheit*/
    
    lower = 0; // lower limit of temperature table
    step = 20; // step size
    printf("Celsius to Fahrenheit Table\n");
    celsius = upper; // initialize celsius to upper limit
    while (celsius >= lower) {
        fahr = (celsius * 9 / 5) + 32;
        printf("%3d %6d\n", celsius, fahr);
        celsius = celsius - step;
    }
}