#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(push_swap_utils, itShouldGetLabelFromSwapAOperation) {
	t_operations op = sa;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("sa", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromSwapBOperation) {
	t_operations op = sb;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("sb", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromSSOperation) {
	t_operations op = ss;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("ss", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromPushAOperation) {
	t_operations op = pa;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("pa", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromPushBOperation) {
	t_operations op = pb;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("pb", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromRotateAOperation) {
	t_operations op = ra;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("ra", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromRotateBOperation) {
	t_operations op = rb;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("rb", result);
	free(result);
}


TEST(push_swap_utils, itShouldGetLabelFromRotateBothOperation) {
	t_operations op = rr;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("rr", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromReverseRotateAOperation) {
	t_operations op = rra;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("rra", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromReverseRotateBOperation) {
	t_operations op = rrb;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("rrb", result);
	free(result);
}

TEST(push_swap_utils, itShouldGetLabelFromReverseRotateBothOperation) {
	t_operations op = rrr;

	char *result = ft_get_operation_label(op);

	ASSERT_STREQ("rrr", result);
	free(result);
}

TEST(push_swap_utils, itShouldConvertNumbersInputToAUniDimensionalIntegerArray) {
	const char **input;
	input = (const char *[]){
		"1 2 3",
		"+42 -100",
		"2147483647 -2147483648",
		NULL
	};

	t_int_arr result = ft_convert_numbers_input_to_int_array(input);

	ASSERT_EQ(7, result.len);
	ASSERT_EQ(1, result.numbers[0]);
	ASSERT_EQ(2, result.numbers[1]);
	ASSERT_EQ(3, result.numbers[2]);
	ASSERT_EQ(42, result.numbers[3]);
	ASSERT_EQ(-100, result.numbers[4]);
	ASSERT_EQ(2147483647, result.numbers[5]);
	ASSERT_EQ(-2147483648, result.numbers[6]);

	free(result.numbers);
}

TEST(push_swap_utils, itShouldSortAnIntegerArray) {
	t_int_arr arr;
	arr.len = 7;
	arr.numbers = (int *)malloc(sizeof(int) * 7);
	ft_memmove(arr.numbers, (int[]){1, 2, 3, 42, -100, 2147483647, -2147483648}, 7 * sizeof(int));

	ft_quicksort(arr);

	ASSERT_EQ(-2147483648, arr.numbers[0]);
	ASSERT_EQ(-100, arr.numbers[1]);
	ASSERT_EQ(1, arr.numbers[2]);
	ASSERT_EQ(2, arr.numbers[3]);
	ASSERT_EQ(3, arr.numbers[4]);
	ASSERT_EQ(42, arr.numbers[5]);
	ASSERT_EQ(2147483647, arr.numbers[6]);

	free(arr.numbers);
}
