#include "debug.h"


static int simpleInstruction(const char* name, int offset){
  printf("%s\n", name);
  return offset+1;
}
 static int constantInstruction(const char* name, Chunk* chunk, int offset){
  uint8_t constant = chunk->code[offset+1].code;
  printf("%-16s  %4d'", name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset+2;
}

void disassembleChunk(Chunk* chunk, const char* name){
  printf("===== %s =======\n", name);
  
  for(int offset = 0; offset<chunk->count;){
    offset = disassembleInstruction(chunk, offset);
  }

}

int disassembleInstruction(Chunk* chunk, int offset){
  printf("%04d ", offset);

  CodeTuple instruction = chunk->code[offset];
  uint8_t op_code = instruction.code;
  int line = instruction.line;
  
  printf("%4d ", line);
  
  switch (op_code) {
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", chunk, offset);
    default:
      printf("Unkown opcode %d\n", op_code);
    return offset+1;
  }
}
