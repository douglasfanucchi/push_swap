NAME=push_swap
FILES=main ft_dlist ft_stack ft_stack_operations push_swap push_swap_utils\
	ft_state ft_parser ft_quicksort ft_parser_utils
SRC=$(addsuffix .c,$(FILES))
OBJECTS=$(addsuffix .o,$(FILES))
TEST_FILES:=$(filter-out main, $(FILES))
TEST_FILES:=$(addprefix tests/,$(TEST_FILES))
TEST_FILES:=$(addsuffix _test.cc, $(TEST_FILES))
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

tests.a: $(filter-out main.o,$(OBJECTS))
	ar rcs tests.a $^

tests: $(TEST_FILES) tests.a
	@cd tests && \
	cmake -S . -B build &&\
	cmake --build build &&\
	cd build &&\
	ctest --output-on-failure
	@rm -rf tests.a

.PHONY: clean fclean re
