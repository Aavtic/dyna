#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dyna.h"

#define PRINT_ALL(format, typecast) for (size_t i = 0; i<d_array->length; ++i) {\
                                                    printf(format, ((typecast *)d_array->start)[i]);\
                                                    printf("%s", (i == d_array->length-1)? "\n" : ", ");}
void da_print(DArray *d_array, Types type) {
    /*INTEGER,*/
    /*CHARACTER,*/
    /*BOOL,*/
    /*FLOAT,*/
    /*DOUBLE,*/
    /*STRING,*/

    switch (type) {
        case INTEGER:
            PRINT_ALL("%d",  int);
            break;
        case CHARACTER:
            PRINT_ALL("%c",  char);
            break;
        case BOOL:
            PRINT_ALL("%d",  int);
            break;
        case FLOAT:
            PRINT_ALL("%f",  float);
            break;
        case DOUBLE:
            PRINT_ALL("%lf",  double);
            break;
        case STRING:
            PRINT_ALL("%s",  char*);
            break;
    }

}


void da_append(DArray *da_array, void* element) {
    if (da_array->length + 1 <= da_array->capacity) {
        void* ptr = (char *)da_array->start  + (da_array->length * da_array->size);
        memcpy(ptr, element, da_array->size);
        da_array->length++;
    } else {
        // Incase capacity is 0 for some reason
        size_t new_capacity = (da_array->capacity + 1) * 2;
        int* new_start = reallocarray(da_array->start, new_capacity, da_array->size);
        /*int* new_start = realloc(da_array->start, new_capacity);*/
        if (new_start == NULL){
            fprintf(stderr, "ERROR: Can't allocate memory for array\nBuy More Ram please");
            exit(1);
        }
        da_array->start = new_start;
        da_array->capacity = new_capacity;
        void* ptr = (char *) da_array->start + (da_array->length * da_array->size);
        da_array->length++;
        memcpy(ptr, element, da_array->size);
    }
}

DArray da_alloc(size_t initial_capacity, size_t size) {
    void* array_ptr = malloc(initial_capacity * size);
    if (array_ptr == NULL) {
        fprintf(stderr, "ERROR: Can't allocate memory for array\nBuy More Ram please");
        exit(1);
    }
    DArray darray;
    darray.start = array_ptr;
    darray.size = size;
    darray.capacity = initial_capacity;
    darray.length = 0;

    return darray;
}
