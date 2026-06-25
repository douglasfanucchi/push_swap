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
	const char *input[] = {
		"1 2 3",
		"+42 -100",
		"2147483647 -2147483648",
		NULL
	};

	t_arr result = ft_convert_numbers_input_to_int_array(input);

	int *numbers = (int *)result.elements;
	ASSERT_EQ(7, result.len);
	ASSERT_EQ(1, numbers[0]);
	ASSERT_EQ(2, numbers[1]);
	ASSERT_EQ(3, numbers[2]);
	ASSERT_EQ(42, numbers[3]);
	ASSERT_EQ(-100, numbers[4]);
	ASSERT_EQ(2147483647, numbers[5]);
	ASSERT_EQ(-2147483648, numbers[6]);

	free(result.elements);
}
