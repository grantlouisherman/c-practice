#include <iostream>
#include<string>
#include<vector>
#include <memory>

void execute(char s, std::shared_ptr<std::vector<int>> vec_ptr, int* mem_ptr){
  if(s == '>'){
    (*mem_ptr)++;
  }

  if(s == '>'){
    (*mem_ptr)++;
  }

  if(s == '+'){
    int idx = *mem_ptr;
    (vec_ptr->at(idx))++;
  }

  if(s == '-'){
    int idx = *mem_ptr;
    (vec_ptr->at(idx))--;
    }
}

int execute_loop(std::string line, int idx, std::shared_ptr<std::vector<int>> vec_ptr, int* mem_ptr){
  std::vector<char> loop_stack;
  int p = idx;
  while(line[p] != ']'){
    loop_stack.push_back(line[p]);
    p++;
  }
  int instruction_ptr = 0;
  while(true){
    int curr_idx = *mem_ptr;
    int cell = vec_ptr->at(curr_idx);
    if(cell == 0){
      break;
    }
    char curr_instruction = loop_stack[instruction_ptr];
    execute(curr_instruction, vec_ptr, mem_ptr);
    instruction_ptr++;
    if(instruction_ptr >loop_stack.size()){
      instruction_ptr = 0;
    }
  }
  return p+1;
}
void interpret(std::string line, std::shared_ptr<std::vector<int>> vec_ptr, int* mem_ptr){
    for(int i =0; i<sizeof(line);i++){
      char s = line[i];
      if(s == '['){
        int new_idx = execute_loop(line, i+1, vec_ptr, mem_ptr);
        i = new_idx;
      } else {
        execute(s, vec_ptr, mem_ptr);
      }
      


  } 
}
int main(){
  std::vector<int> memory(30000, 0);
  int mem_ptr = 0;
  std::string line;
  std::cout << ">>>  "; 
  std::shared_ptr<std::vector<int>> vptr  = std::make_shared<std::vector<int>>(memory);
  while(std::getline(std::cin, line)){
    std::cout << ">>>  ";
    interpret(line, vptr, &mem_ptr);
  }

  return 0;
}
