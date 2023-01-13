NAME = push_swap
FILES := push_swap.c movements/generic.c movements/swap.c movements/rotate.c \
		 movements/push.c movements/reverse_rotate.c algorithms/quick_sort.c \
		 algorithms/radix.c algorithms/small_stack_sort.c check_order.c \
		 stack.c
SRCS := $(addprefix sources/, $(FILES));
OBJS := $(FILES:.c=.o)
OBJS := $(OBJS:movements/%=%)
OBJS := $(OBJS:algorithms/%=%)
LIBS = -lft
LIB_FLAGS = -Llib/libft -lft
FLAGS = -Wall -Werror -Wextra -I lib/libft -I./includes -g3
LIBFT = lib/libft/libft.a

all: | libft

libft:
	@make -C lib/libft
	@make $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIB_FLAGS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	make clean -C lib/libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C lib/libft
	rm -rf $(NAME)
