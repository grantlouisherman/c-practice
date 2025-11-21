#include<stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE 5
void selection_sort(int arr[], int size){
  if(size <= 1){
    return;
  }
  int head = size - 1;
  int largest_number = -1;
  int number_index = 0;
  for(int i = 0; i<size; i++){
    if(arr[i] > largest_number){
      largest_number =  arr[i];
      number_index = i;
    }
  }
  int target = arr[head];
  arr[head] = largest_number;
  arr[number_index] = target;
  return selection_sort(arr, size-1);
}

int main(){
  int arr[ARRAY_SIZE] = {0,0,0,0,0};
  int ap = 0;
  printf("Enter 10 numbers to be sorted\n");
  while(ap < ARRAY_SIZE){
    printf("Enter number, you have %d left:   \n", (ARRAY_SIZE - ap));
    scanf("%d", &arr[ap]);
    ap = ap + 1;
  }
  printf("Done entering\n");
  selection_sort(arr, ARRAY_SIZE);
  for(int i = 0; i<ARRAY_SIZE;i++){
    printf("%d\n", arr[i]);
  }
  return 0;
}
