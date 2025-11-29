#include "common.h"
#include "vm.h"
#include <stdio.h>
#include "value.h"
#include "debug.h"


VM vm;

static void resetStack(){
  vm.stackTop = vm.stack;
}
static InterpretResult run(){
  #define READ_BYTE()(*vm.ip++)
  #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

  #ifdef DEBUG_TRACE_EXECUTION
    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
  #endif
  printf("INSTRUCTION POINTER %d\n", *vm.ip);
  for(;;){
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();
        printValue(constant);
        printf("\n");
        break;
      }      

      case OP_RETURN:
        return INTERPRET_OK;
        
    }
  }

  #undef READ_BYTE
  #undef READ_CONSTANT
}

void initVM(){
  resetStack();
}

void freeVM(){

}

InterpretResult interpret(Chunk* chunk){
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}

void push(Value value){
  *vm.stackTop = value;
  vm.stackTop++;
}

Value pop(){
  Value head = *vm.stackTop;
  vm.stackTop--;
  return head;
}
