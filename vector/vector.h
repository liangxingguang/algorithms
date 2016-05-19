#ifndef _VECTOR_H
#define _VECTOR_H
#include<stdlib.h>
#include<stdbool.h>

typedef Struct vector *vector;

vector vector_new(size_t hint, size_t size, void(*freesh)(void*));
void vector_free(vector v);
size_t vector_size(vector v);
bool vector_add(vector v, void *elem);
bool vector_get(vector v, void *elem);
bool vector_remove(vector v, size_t i, void *elem);
bool vector_insert(vector v, size_t i, void *elem);
bool vector_empty(vector v);
bool vector_clear(vector v);
#endif

