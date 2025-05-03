# Dyna

generic dynamic array in C supporting various data types such as int, char, float, and char* (strings).

Features
    1. - Dynamically resizes on demand
    2. - Type-safe via macro-based initialization
    3. - Supports any data type
    4. - Easy printing with format specifiers

## Usage

### Initialization

Use the DYNA_INIT(Type) macro to define a dynamic array type:

```c
DYNA_INIT(int) Dyna;
Dyna dyna = {0};
dyna.start = malloc(DYNA_INITIAL_CAP * sizeof(int));
dyna.capacity = DYNA_INITIAL_CAP;
dyna.size = sizeof(int);
```

### Append Elements

Use dyna_append(&array, value) to add elements dynamically:

```c
for (int i = 0; i < 50; ++i) {
    dyna_append(&dyna, i);
}
```

### Print Elements

Use dyna_print(&array, format) to print the array:

```c
dyna_print(&dyna, "%i");  // For ints
```

### Free Memory

Don't forget to free the memory:

```c
dyna_free(&dyna);
```

## Examples

### Integers

```c
DYNA_INIT(int) Dyna;
Dyna dyna = {0};
dyna.start = malloc(DYNA_INITIAL_CAP * sizeof(int));
dyna.capacity = DYNA_INITIAL_CAP;
dyna.size = sizeof(int);

for (int i = 0; i < 50; ++i) dyna_append(&dyna, i);

dyna_print(&dyna, "%i");
dyna_free(&dyna);
```

### Characters

```c
DYNA_INIT(char) DynaChar;
DynaChar dynac = {0};
dynac.start = malloc(DYNA_INITIAL_CAP * sizeof(char));
dynac.capacity = DYNA_INITIAL_CAP;
dynac.size = sizeof(char);

for (int i = 0; i < 26; ++i) dyna_append(&dynac, 'a' + i);

dyna_print(&dynac, "'%c'");
dyna_free(&dynac);
```

### Floats

```c
DYNA_INIT(float) DynaFloat;
DynaFloat dynaf = {0};
dynaf.start = malloc(DYNA_INITIAL_CAP * sizeof(float));
dynaf.capacity = DYNA_INITIAL_CAP;
dynaf.size = sizeof(float);

for (int i = 0; i < 10; ++i) dyna_append(&dynaf, i + 0.5f);

dyna_print(&dynaf, "%f");
dyna_free(&dynaf);
```

### Strings

```c
DYNA_INIT(char*) DynaStr;
DynaStr dynas = {0};
dynas.start = malloc(DYNA_INITIAL_CAP * sizeof(char*));
dynas.capacity = DYNA_INITIAL_CAP;
dynas.size = sizeof(char*);

for (int i = 0; i < 10; ++i) dyna_append(&dynas, "Hello There");

dyna_print(&dynas, "\"%s\"");
dyna_free(&dynas);


# This is my Implementation of Dynamic Array in C.

I am still learning and experimenting things out on myself. There could be problems with my implementation of dynamic array in C. If you find any mistakes or have any suggestions please do let me know.

```


## This is my Implementation of Dynamic Array in C.

I am still learning and experimenting things out on myself. If you find any mistakes or have any suggestions please do let me know.
