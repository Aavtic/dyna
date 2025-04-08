compile: main.c
	gcc -ggdb -o main main.c

run: main
	./main

clean: main
	rm main
