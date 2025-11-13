#include <stdio.h>
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INTIAL_BALANCE 100.00
#define INTEREST_RATE_CONSTANT 100.0
int main(){
  int i,low_rate, num_years, year;
  double value[5];
  printf("Enter your interst rate: ");
  scanf("%d", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);
  printf("\n Years");
  for (int i =0;i < NUM_RATES; i++) {
    printf("%6d%%", low_rate+i);
    value[i] = INTIAL_BALANCE;
  }
  printf("\n");
  for(year=1;year<=num_years;year++){
    printf("%3d      ", year);
    for(i = 0; i< NUM_RATES;i++){
      value[i] += (low_rate + i) / INTEREST_RATE_CONSTANT * value[i];
      printf("%7.2f", value[i]);
    }
    printf("\n");
  
  }
  return 0;
}
