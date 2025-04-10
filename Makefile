compile: main.c
	gcc -Werror -Wall -Wextra -pedantic -ggdb -o main main.c

run: main
	./main

clean: main
	rm main
