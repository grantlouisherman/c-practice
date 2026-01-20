#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
  char file_contents;
  FILE *fp;
  fp = fopen("/Users/gherma/Desktop/code_misc/c-practice/unix_utils/wcat.c", "r");
  if(fp == NULL){
    printf("File Error");
    return 0;
  }
  while((file_contents = fgetc(fp)) != EOF){
    printf("%c", file_contents);
  }
  fclose(fp);
  return 0;
}
