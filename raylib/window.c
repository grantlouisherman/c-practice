#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <string.h>

#define VMAP_COMMAND "vmmap"
#define PROCESS_STATS_FILE "process.txt"
#define PROCESS_COMMAND "top | head -n 20 > "
#define PROCESS_SYS_CALL PROCESS_COMMAND PROCESS_STATS_FILE
void create_window()
{
 const int sW = 800;
  const int sH = 450;

  InitWindow(sW, sH, "raylib example");

  SetTargetFPS(60);
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Its a mi, a windiow", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();  
}

void read_command_file(){
  FILE* fp;
  fp = fopen(PROCESS_STATS_FILE, "r");
  if(fp == NULL){
    printf("File READ_ERROR");
    return;
  }
  if(fseek(fp, 0L, SEEK_END) != 0){
    printf("Seek Failed\n");
    fclose(fp);
    return;
  }
  long bs = ftell(fp);
  rewind(fp);
  char* file_buffer = (char*)malloc(sizeof(char)* bs+1);
  if(fread(file_buffer, sizeof(char), bs, fp) == 0){
    printf("Could not read buffer\n");
    return;
  }
  printf("Read Completed\n");
  printf("Starting read loop\n");
  int length = bs / sizeof(char);
  printf("Array Size: %i\n", length);
  for(int i=0;i<length;i++){
    if(strcmp(&file_buffer[i],"\n") != -1){
      printf("NEW_LINE_FOUND\n");
    }
    printf("%c", file_buffer[i]);
  }

}
int main()
{
  
  int returnCode = system(PROCESS_SYS_CALL);
  if(returnCode == 0){
      printf("Your return Code: {%d}", returnCode);
    } else {
      printf("Problem");
    }
  read_command_file();
  return 0;
}
