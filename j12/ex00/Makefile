SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)

all: ft_display_file

ft_display_file: $(OBJ)
	gcc -o ft_display_file $^

obj/%.o: src/%.c
	gcc -c -Werror -Wextra -Wall $< -o $@

clean:
	rm -rf obj/*.o

fclean: clean
	rm ft_display_file

.PHONY: all clean fclean
