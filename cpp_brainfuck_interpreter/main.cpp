#include <iostream>
#include<string>
#include<vector>
#include <memory>

void interpret(std::string line, std::vector<int>* vec_ptr, int* mem_ptr){
    if(line == ">"){
      (*mem_ptr)++;
    }
    if(line == "+"){
      int idx = *mem_ptr;
      (vec_ptr->at(idx))++;
    }

  } 

int main(){
  std::vector<int> memory(30000, 0);
  int mem_ptr = 0;
  std::string line;
  std::cout << ">>>  "; 
  
  while(std::getline(std::cin, line)){
    std::cout << ">>>  ";
    interpret(line, &memory, &mem_ptr);
  }

  return 0;
}
