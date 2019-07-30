gcc main.c -o bin					\
	`pkg-config --cflags gtk+-3.0`	\
	`pkg-config --libs gtk+-3.0`	\
	-export-dynamic					\
	-Wall -Wextra
