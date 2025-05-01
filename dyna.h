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
    void* start;      // starting address of the array
    size_t size;      // size of a single element
    size_t length;    // number of elements currently stored
    size_t capacity;  // maximum number of elements able to be stored
} DArray;



DArray da_alloc(size_t initial_capacity, size_t size);

#define ELEMENT(elem) ((typeof(elem)[]){elem})
void da_append(DArray *da_array, void* element);
void da_print(DArray *array, Types type);


#endif
