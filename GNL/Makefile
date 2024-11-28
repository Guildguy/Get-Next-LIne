TARGET = gnl_test

CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=42

CC = cc

SRCS = get_next_line.c get_next_line_utils.c main.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET) archive.txt

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re