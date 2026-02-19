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
