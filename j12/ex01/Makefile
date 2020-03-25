PNAME = ft_cat
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)

all: $(PNAME)

$(PNAME): $(OBJ)
	gcc -o $(PNAME) $^

obj/%.o: src/%.c
	gcc -c -Werror -Wextra -Wall $< -o $@

clean:
	rm -rf obj/*.o

fclean: clean
	rm $(PNAME)

.PHONY: all clean fclean
