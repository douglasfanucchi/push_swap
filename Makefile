NAME=push_swap
SRC=main.c
OBJECTS=$(SRC:.c=.o)
CC=cc
CFLAGS=-Wall -Werror -Wextra
LIBS=-L libft
LIBFT=libft/libft.a
INCLUDES=-I libft/includes
SANITIZE:=-fsanitize=address -g -O1 -fno-omit-frame-pointer -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(SANITIZE) $(LIBS) $^ -lft -o $@

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(SANITIZE) -c $< $(INCLUDES) -o $@

clean:
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
