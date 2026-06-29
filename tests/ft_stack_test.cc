#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_stack, itShouldInitializeAStack) {
	t_stack	stack;

	ft_stack_init(&stack);

	ASSERT_EQ(0, stack.size);
	ASSERT_EQ(0, stack.arr_size);
	ASSERT_EQ(nullptr, stack.arr);
}

TEST(ft_stack, itShouldClearTheStack) {
	t_stack stack;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr_size = 1;
	stack.size = 1;
	stack.arr[0] = 42;

	ft_stack_clear(&stack);

	ASSERT_EQ(nullptr, stack.arr);
	ASSERT_EQ(0, stack.arr_size);
	ASSERT_EQ(0, stack.size);
}

TEST(ft_stack, itShouldConvertAnArrayOfIntegerIntoANormalizedStack) {
	t_arr arr;
	arr.len = 7;
	arr.elements = malloc(sizeof(int) * 7);
	ft_memmove(arr.elements, (int[]){1, 2, 3, 42, -100, 2147483647, -2147483648}, 7 * sizeof(int));

	t_stack stack = ft_int_arr_to_normalized_stack(&arr);

	ASSERT_NE(nullptr, stack.arr);
	ASSERT_EQ(7, stack.size);
	ASSERT_EQ(8, stack.arr_size);
	ASSERT_EQ(2, stack.arr[0]);
	ASSERT_EQ(3, stack.arr[1]);
	ASSERT_EQ(4, stack.arr[2]);
	ASSERT_EQ(5, stack.arr[3]);
	ASSERT_EQ(1, stack.arr[4]);
	ASSERT_EQ(6, stack.arr[5]);
	ASSERT_EQ(0, stack.arr[6]);

	free(stack.arr);
	free(arr.elements);
}
