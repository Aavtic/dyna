#include "../dyna.h"


void print_int(DArray *da_array) {
    int* array = (int *) da_array->start;

    for (size_t i=0; i<da_array->length; ++i) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(void) {
    DArray d_array = da_alloc(3, sizeof(double));

    /*for (int i=0; i<101; ++i) {*/
    /*    da_append(&d_array, ELEMENT('a'));*/
    /*}*/

    for (int i=0; i<50; ++i) {
        da_append(&d_array, ELEMENT(1.23));
    }
    da_print(&d_array, DOUBLE);

    printf("Array size: %ld\nArray length: %ld\nArray capacity: %ld\n", d_array.size, d_array.length, d_array.capacity);

    return 0;
} 
