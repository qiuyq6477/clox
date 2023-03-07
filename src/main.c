#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
    initVM();

    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);
    writeChunk(&chunk, OP_ADD);
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);
    writeChunk(&chunk, OP_DIVIDE);


    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);
    freeVM();

    freeChunk(&chunk);
    return 0;
}