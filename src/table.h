#ifndef CLOX_TABLE_H
#define CLOX_TABLE_H

#include "value.h"

typedef struct {
  ObjString *key;
  Value value;
} Entry;

typedef struct {
  int count;
  int capacity;
  Entry *entries;
} Table;

void freeTable(Table *table);
void initTable(Table *table);
void markTable(Table* table);
void tableAddAll(Table *from, Table *to);
bool tableDelete(Table *table, ObjString *key);
ObjString* tableFindString(Table* table, const char* chars, int length, uint32_t hash);
bool tableGet(Table *table, ObjString *key, Value *value);
void tableRemoveWhite(Table* table);
bool tableSet(Table *table, ObjString *key, Value value);

#endif
