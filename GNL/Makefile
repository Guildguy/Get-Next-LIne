CC = CC
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

FUNCTIONS = get_next_line main

OBJ = $(FUNCTIONS:=.o)
NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
%.o: $.c
	$(CC) $(CFLAGS) -I. -c -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re