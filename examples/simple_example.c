/*
This file contains all the examples for creating and freeing 
a dynamic array with primitive types and string.
 */



#include <stdio.h>
#include <stdlib.h>
#include "../dyna.h"

int main() {
    // Dynamic Array of Int
    DYNA_INIT(int) Dyna;

    Dyna dyna = {0};

    dyna.start = malloc(DYNA_INITIAL_CAP * sizeof(int));
    dyna.capacity = DYNA_INITIAL_CAP; // 16
    dyna.size = sizeof(int);

    for (int i=0; i<50; ++i) {
        dyna_append(&dyna, i);
    }


    dyna_print(&dyna, "%i");
    dyna_free(&dyna);
    /* OUTPUT
    || [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49]
    || length: 50
    || capacity: 70
     */


    // Dynamic Array of Chars
    DYNA_INIT(char) DynaChar;

    DynaChar dynac = {0};

    dynac.start = malloc(DYNA_INITIAL_CAP * sizeof(char));
    dynac.capacity = DYNA_INITIAL_CAP; // 16
    dynac.size = sizeof(char);

    for (int i=0; i<26; ++i) {
        dyna_append(&dynac, 'a'+i);
    }


    dyna_print(&dynac, "'%c'");
    dyna_free(&dynac);
    /* OUTPUT
    || ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    || length: 26
    || capacity: 34 */

    printf("length: %zu\ncapacity: %zu\n", dyna.length, dyna.capacity);


    // Dynamic Array of Floats
    DYNA_INIT(float) DynaFloat;

    DynaFloat dynaf = {0};

    dynaf.start = malloc(DYNA_INITIAL_CAP * sizeof(float));
    dynaf.capacity = DYNA_INITIAL_CAP; // 16
    dynaf.size = sizeof(float);

    for (int i=0; i<10; ++i) {
        dyna_append(&dynaf, i + 0.5);
    }


    dyna_print(&dynaf, "%f");

    printf("length: %zu\ncapacity: %zu\n", dyna.length, dyna.capacity);
    dyna_free(&dynaf);

    /* OUTPUT
        || [0.500000, 1.500000, 2.500000, 3.500000, 4.500000, 5.500000, 6.500000, 7.500000, 8.500000, 9.500000]
        || length: 10
        || capacity: 16
    */


    /**/
    /*// Dynamic Array of Strings*/
    DYNA_INIT(char*) DynaStr;
    
    DynaStr dynas = {0};
    
    dynas.start = malloc(DYNA_INITIAL_CAP * sizeof(char*));
    dynas.capacity = DYNA_INITIAL_CAP;
    dynas.size = sizeof(char*);
    
    for (int i=0; i<10; ++i) {
        dyna_append(&dynas, "Hello There");
    }
    
    
    dyna_print(&dynas, "\"%s\"");
    
    printf("length: %zu\ncapacity: %zu\n", dyna.length, dyna.capacity);
    dyna_free(&dynas);

    /* OUTPUT
    || ["Hello There", "Hello There", "Hello There", "Hello There", "Hello There", "Hello There", "Hello There", "Hello There", "Hello There", "Hello There"]
    || length: 10
    || capacity: 16*/

    return 0;
}
