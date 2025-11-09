#include <stdio.h>
#define CONVERSION_CONSTANT (5.0/9.0)
#define LOWER 0
#define UPPER 300
#define STEP 20
int main(){
    float fahr, celsius;
    fahr = LOWER;
    while(fahr <= UPPER){
        celsius = CONVERSION_CONSTANT * (fahr-32.0);
        printf("Farenheit ------  Celsius");
        printf("%4.0f  %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}