#ifndef clox_vm_h
#define clox_vm_h

#include "memory.h"
#include "chunk.h"
#include "value.h"
#include "table.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
  ObjFunction* function; // 指向被调用函数
  uint8_t* ip; // 返回地址
  Value* slots;
} CallFrame;

typedef struct {
  CallFrame frames[FRAMES_MAX];
  int frameCount;
  Value stack[STACK_MAX];
  Value* stackTop; //指针指向数组中栈顶元素的下一个元素位置
  Obj* objects;
  Table strings;
  Table globals;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);

void push(Value value);
Value pop();

#endif