#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* start;
    size_t length;
    size_t capacity;
} DArray;


void da_print(DArray *array) {
    int* start = array->start;
    
    for (int i=0; i<array->length; ++i) {
        printf("%d", *start);
        start++;
    }
}

// For now I am only creating for integers.
void da_append(DArray *da_array, int element) {
    if (da_array->length + 1 < da_array->capacity) {
        *(da_array->start + (int) da_array->length) = element;
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
        *(da_array->start + (int) da_array->length) = element;
        da_array->length++;
    }
}

DArray da_alloc(size_t initial_capacity) {
    int* array_ptr = malloc(initial_capacity);
    if (array_ptr == NULL) {
        fprintf(stderr, "ERROR: Can't allocate memory for array\nBuy More Ram please");
        exit(1);
    }
    DArray darray;
    darray.start = array_ptr;
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
