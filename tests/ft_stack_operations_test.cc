#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_stack, itShouldPushAnElementIntoAnEmptyStack) {
	t_stack stack;
	stack.size = 0;
	stack.arr_size = 0;
	stack.arr = NULL;

	int size = ft_stack_push(&stack, 42);

	ASSERT_EQ(1, size);
	ASSERT_EQ(1, stack.size);
	ASSERT_EQ(1, stack.arr_size);
	ASSERT_NE(nullptr, stack.arr);
	ASSERT_EQ(42, stack.arr[0]);

	free(stack.arr);
}

TEST(ft_stack, itShouldPushAnElementIntoAFullFilledStackShouldDoubleItsSizeAndAddTheElementAtItsTop) {
	t_stack stack;
	stack.size = 1;
	stack.arr_size = 1;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr[0] = 42;

	int size = ft_stack_push(&stack, 43);

	ASSERT_EQ(2, size);
	ASSERT_EQ(2, stack.size);
	ASSERT_EQ(2, stack.arr_size);
	ASSERT_NE(nullptr, stack.arr);
	ASSERT_EQ(43, stack.arr[0]);
	ASSERT_EQ(42, stack.arr[1]);

	free(stack.arr);
}

TEST(ft_stack, itShouldPushAnElementIntoANonEmptyButNotFullFilledStack) {
	t_stack stack;
	stack.size = 2;
	stack.arr_size = 4;
	stack.arr = (int *)malloc(sizeof(int) * 4);
	stack.arr[0] = 43;
	stack.arr[1] = 42;

	int size = ft_stack_push(&stack, 44);

	ASSERT_EQ(3, size);
	ASSERT_EQ(3, stack.size);
	ASSERT_EQ(4, stack.arr_size);
	ASSERT_NE(nullptr, stack.arr);
	ASSERT_EQ(44, stack.arr[0]);
	ASSERT_EQ(43, stack.arr[1]);
	ASSERT_EQ(42, stack.arr[2]);

	free(stack.arr);
}

TEST(ft_stack, itShouldPopAnElementFromAStackWithOneElement) {
	t_stack stack;
	stack.size = 1;
	stack.arr_size = 1;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr[0] = 42;

	int result = ft_stack_pop(&stack);

	ASSERT_EQ(0, result);
	ASSERT_EQ(0, stack.size);
	ASSERT_EQ(0, stack.arr_size);
	ASSERT_EQ(nullptr, stack.arr);
}

TEST(ft_stack, itShouldPopAnElementFromAStackWithMoreThanOneElement) {
	t_stack stack;
	stack.size = 2;
	stack.arr_size = 2;
	stack.arr = (int *)malloc(sizeof(int) * 2);
	stack.arr[0] = 43;
	stack.arr[1] = 42;

	int result = ft_stack_pop(&stack);

	ASSERT_EQ(1, result);
	ASSERT_EQ(1, stack.size);
	ASSERT_EQ(2, stack.arr_size);
	ASSERT_NE(nullptr, stack.arr);
	ASSERT_EQ(42, stack.arr[0]);

	free(stack.arr);
}

TEST(ft_stack, itShouldPeekTheElementAtTheTopOfStack) {
	t_stack stack;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr_size = 1;
	stack.size = 1;
	stack.arr[0] = 42;

	int result = ft_stack_peek(&stack);

	ASSERT_EQ(42, result);
	free(stack.arr);
}

TEST(ft_stack, itShouldRotateAStackWithOneElement) {
	t_stack stack;
	stack.size = 1;
	stack.arr_size = 1;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr[0] = 42;

	ft_stack_rotate(&stack);

	ASSERT_EQ(42, stack.arr[0]);
	ASSERT_EQ(1, stack.arr_size);
	ASSERT_EQ(1, stack.size);

	free(stack.arr);
}

TEST(ft_stack, itShouldRotateAStackWithMoreThanOneElement) {
	t_stack stack;
	stack.arr_size = 4;
	stack.size = 3;
	stack.arr = (int *)malloc(sizeof(int) * 4);
	stack.arr[0] = 44;
	stack.arr[1] = 43;
	stack.arr[2] = 42;

	ft_stack_rotate(&stack);

	ASSERT_EQ(43, stack.arr[0]);
	ASSERT_EQ(42, stack.arr[1]);
	ASSERT_EQ(44, stack.arr[2]);
	ASSERT_EQ(3, stack.size);
	ASSERT_EQ(4, stack.arr_size);

	free(stack.arr);
}


TEST(ft_stack, itShouldReverseRotateAStackWithOneElement) {
	t_stack stack;
	stack.arr_size = 1;
	stack.size = 1;
	stack.arr = (int *)malloc(sizeof(int));
	stack.arr[0] = 42; 

	ft_stack_reverse_rotate(&stack);

	ASSERT_EQ(42, stack.arr[0]);
	ASSERT_EQ(1, stack.arr_size);
	ASSERT_EQ(1, stack.size);

	free(stack.arr);
}

TEST(ft_stack, itShouldReverseRotateAStackWithMoreThanOneElement) {
	t_stack stack;
	stack.arr_size = 4;
	stack.size = 3;
	stack.arr = (int *)malloc(sizeof(int) * 4);
	stack.arr[0] = 42;
	stack.arr[1] = 43;
	stack.arr[2] = 44;

	ft_stack_reverse_rotate(&stack);

	ASSERT_EQ(44, stack.arr[0]);
	ASSERT_EQ(42, stack.arr[1]);
	ASSERT_EQ(43, stack.arr[2]);
	ASSERT_EQ(3, stack.size);
	ASSERT_EQ(4, stack.arr_size);
	
	free(stack.arr);
}
