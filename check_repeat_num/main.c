#include <stdbool.h>
#include <stdio.h>

int main(){
    bool digit_seen[10] = {false};
    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while(n > 0){
        digit = n % 10;
        printf("Digit: %d\n", digit);
        if(digit_seen[digit]){
            break;
        }
        digit_seen[digit] = true;
        n/=10;
        printf("Current N value:  %ld\n", n);
    }
    if(n>0){
        printf("Repeated Digit Found");
        return 0;
    } 
    printf("No Repeat Digits");

    return 0;
}