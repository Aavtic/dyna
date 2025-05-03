#ifndef _DYNA
#define _DYNA

#include <stdio.h>
#include <stdlib.h>

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


// NEW Dyna Version

#define DYNA_INITIAL_CAP 16

#define DYNA_INIT(type)                       \
    typedef struct {                          \
        size_t length;                        \
        size_t capacity;                      \
        size_t size;                          \
        type* start;         \
    }

#define DYNA_REALLOCATE(dyna, length)                                                                 \
    do {                                                                                              \
        if (length == (dyna)->capacity) {                                                             \
            (dyna)->start = reallocarray((dyna)->start, ((dyna)->capacity + 1) * 2, (dyna)->size);    \
            if ((dyna)->start != NULL) {                                                              \
                (dyna)->capacity = (dyna->capacity +1) * 2;                                           \
            } else {                                                                                  \
                fprintf(stderr, "ERROR: can't allocate memory. Download more RAM please.");           \
                exit(-1);                                                                             \
            }                                                                                         \
        }                                                                                             \
    } while (0)


#define dyna_append(dyna, element)                    \
    DYNA_REALLOCATE((dyna), (dyna)->length + 1);      \
    (dyna)->start[(dyna)->length++] = element


#define dyna_free(dyna)                               \
    do {                                              \
        free((dyna)->start);                          \
    } while (0)

#define dyna_print(dyna, formatter)                     \
    do {                                                \
        printf("[");                                    \
        for (size_t i=0; i<(dyna)->length; ++i) {       \
            printf(formatter"%s", (dyna)->start[i], (i<(dyna)->length-1) ? ", ":"");        \
        }                                               \
        printf("]\n");                                  \
    } while(0)

#endif
