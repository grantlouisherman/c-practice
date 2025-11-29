#include "common.h"
#include "vm.h"
#include <stdio.h>


VM vm;

static InterpretResult run(){
  #define READ_BYTE()(*vm.ip++)
  #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])  
  for(;;){
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_RETURN:
        return INTERPRET_OK;
      case OP_CONSTANT:
        Value constant = READ_CONSTANT();
        printValue(constant);
        printf("\n");
        break;
    }
  }

  #undef READ_BYTE
  #undef READ_CONSTANT
}

void initVM(){

}

void freeVM(){

}

InterpretResult interpret(Chunk* chunk){
  vm.chunk = chunk;
  uint8_t byte = vm.chunk->code;
  vm.ip = byte;
  return run();
}
