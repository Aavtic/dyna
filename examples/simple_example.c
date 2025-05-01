#include "../dyna.h"


int main(void) {
    DArray array = da_alloc(3, sizeof(int)); 
    da_append(&array, ELEMENT(1));
    da_append(&array, ELEMENT(2));
    da_append(&array, ELEMENT(3));
    da_append(&array, ELEMENT(4));

    da_print(&array, INTEGER);

    return 0;
} 
