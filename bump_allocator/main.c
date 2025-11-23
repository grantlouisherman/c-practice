#include<stdlib.h>
#include<stdio.h>


int* init_heap(size_t size){
  return (int*) malloc(size * sizeof(int));
}

void write_heap(int* heap, int* head_ptr, int value){
  heap[*head_ptr] = value;
  (*head_ptr)++;
}
void free_heap(int* heap_ptr){
  free(heap_ptr);
}
int main(){
  int init_size = 10;
  int* heap_ptr = init_heap(init_size);
  int head_ptr = 0;
  write_heap(heap_ptr, &head_ptr, 10);
  write_heap(heap_ptr, &head_ptr, 6);
  write_heap(heap_ptr, &head_ptr, 4);
  for(int i = 0;i<init_size;i++){
    printf("%d\n", heap_ptr[i]);
  }
  free_heap(heap_ptr);
  printf("%d", *heap_ptr);
  return 0;
}
