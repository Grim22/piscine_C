SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=obj/%.o)

all: do-op

do-op: $(OBJ)
	gcc -o "do-op" $(OBJ)

obj/%.o: src/%.c
	gcc -Iincludes -c -Werror -Wall -Wextra $^ -o $@

clean:
	rm -rf *.o

.PHONY: all clean
