#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void da_print(DArray *array, Types type) {
    void* start = array->start;
    /*INTEGER,*/
    /*CHARACTER,*/
    /*BOOL,*/
    /*FLOAT,*/
    /*DOUBLE,*/
    /*STRING,*/

    for (size_t i=0; i<array->length; ++i) {
        switch (type) {
            case INTEGER:
                printf("%d", (*(int *) start)++);
                break;
            case CHARACTER:
                printf("%c", (*(char *) start)++);
                break;
            case BOOL:
                printf("%d", (*(int *) start)++);
                break;
            case FLOAT:
                printf("%f", (*(float *) start)++);
                break;
            case DOUBLE:
                printf("%lf", (*(double *) start)++);
                break;
            case STRING:
                printf("%s", (char *) start);
                char *start = (char *)start;
                start++;
                break;
        }
        printf("%s", (i == array->length-1)? "\n" : ", ");
    }
}

#define ELEMENT(elem) ((typeof(elem)[]){elem})
void da_append(DArray *da_array, void* element) {
    if (da_array->length + 1 < da_array->capacity) {
        void* ptr = (char *)da_array->start  + (da_array->length * da_array->size);
        memcpy(ptr, element, da_array->size);
        da_array->length++;
    } else {
        // Incase capacity is 0 for some reason
        size_t new_capacity = (da_array->capacity + 1) * 2;
        int* new_start = realloc(da_array->start, new_capacity);
        if (new_start == NULL){
            fprintf(stderr, "ERROR: Can't allocate memory for array\nBuy More Ram please");
            exit(1);
        }

        da_array->start = new_start;
        da_array->capacity = new_capacity;
        void* ptr = (char *) da_array->start + (da_array->length * da_array->size);
        memcpy(ptr, element, da_array->size);
        da_array->length++;
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

int main(void) {
    DArray array = da_alloc(3, sizeof(int)); 
    da_append(&array, ELEMENT(1));
    da_append(&array, ELEMENT(2));
    da_append(&array, ELEMENT(3));
    da_append(&array, ELEMENT(4));

    da_print(&array, INTEGER);

    return 0;
} 
