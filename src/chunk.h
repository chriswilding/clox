#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NEGATE,
  OP_RETURN,
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

int addConstant(Chunk *chunk, Value value);
void freeChunk(Chunk *chunk);
void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);

#endif
