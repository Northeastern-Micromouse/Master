#ifndef MICROMOUSE_CELL_VECTOR_H
#define MICROMOUSE_CELL_VECTOR_H

#include <src/main/c/com/micromouse/maze/cell.h>

typedef struct Vector_c {
  int size;
  int capacity;
  Cell** data;
} Vector_c;

Vector_c* make_vector_c();
Vector_c* make_vector_c_with_size(int n);

void print_vector_c(Vector_c*);

void append_vector_c(Vector_c*, Cell* data);

void double_size_vector_c(Vector_c*);

void free_vector_c(Vector_c *);

#endif  // MICROMOUSE_CELL_VECTOR_H
