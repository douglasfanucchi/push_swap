NAME=pipex
FILES=push_swap.c
SRCS=$(addprefix sources/, $(FILES));
OBJS=$(FILES:.c=.o)
LIBS=-lft
LIB_FLAGS=-Llib/libft -lft
FLAGS=-Wall -Werror -Wextra -I lib/libft -I./includes
LIBFT=lib/libft/libft.a

all: | libft

libft:
	@make -C lib/libft
	@make $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIB_FLAGS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
