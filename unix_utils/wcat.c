#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
  char file_contents;
  FILE *fp;
  if(argc < 1){
    printf("You need to pass in arguments");
    return 0;
  }
  char file_path = *argv[1];
  printf("%c", file_path);
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
