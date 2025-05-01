#ifndef DYNA
#define DYNA

#include <stdio.h>

typedef enum {
    INTEGER,
    CHARACTER,
    BOOL,
    FLOAT,
    DOUBLE,
    STRING,
} Types;

typedef struct {
    void* start;
    size_t size;
    size_t length;
    size_t capacity;
} DArray;



DArray da_alloc(size_t initial_capacity, size_t size);

#define ELEMENT(elem) ((typeof(elem)[]){elem})
void da_append(DArray *da_array, void* element);
void da_print(DArray *array, Types type);


#endif
