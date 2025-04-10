#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* start;
    size_t size;
    size_t length;
    size_t capacity;
} DArray;


void da_print(DArray *array) {
    int* start = array->start;
    
    for (size_t i=0; i<array->length; ++i) {
        printf("%d", *start);
        start++;
    }
}

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
    DArray array = da_alloc(3); 
    da_append(&array, 1);
    da_append(&array, 2);
    da_append(&array, 3);

    da_print(&array);

    return 0;
} 
