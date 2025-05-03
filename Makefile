compile: main.c
	gcc -Werror -Wall -Wextra -pedantic -ggdb -o main main.c

run: main
	./main

run_example: examples/simple_example.c
	gcc -Werror -Wall -Wextra -pedantic -ggdb -o examples/simple_example examples/simple_example.c && examples/simple_example

clean: main
	rm main
