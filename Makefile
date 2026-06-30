NAME=push_swap
FILES=main ft_dlist ft_stack ft_stack_operations push_swap push_swap_utils\
	ft_state ft_parser ft_quicksort ft_parser_utils ft_input_validator\
	ft_swap ft_push ft_rotate ft_reverse_rotate ft_algorithm_n2\
	ft_execute_algorithm
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
tests: SANITIZE:=-fsanitize=address -g -O1 -fno-omit-frame-pointer -fsanitize=undefined
tests_valgrind: SANITIZE:=-g -O1
tests: VALGRIND_FLAG:=OFF
tests_valgrind: VALGRIND_FLAG:=ON

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

norminette:
	norminette $(filter-out main.c, $(SRC)) push_swap.h

test_executable: fclean $(TEST_FILES) tests.a $(LIBFT)
	@cd tests && \
	cmake -S . -B build -DVALGRIND_FLAG=$(VALGRIND_FLAG) &&\
	cmake --build build

tests.a: norminette $(filter-out main.o, $(OBJECTS))
	ar rcs tests.a $(filter-out main.o, $(OBJECTS))

tests_valgrind: test_executable
	cd tests/build &&\
	ctest --output-on-failure -T memcheck
	@rm -rf tests.a

tests: test_executable
	cd tests/build &&\
	ctest --output-on-failure
	@rm -rf tests.a

.PHONY: clean fclean re
