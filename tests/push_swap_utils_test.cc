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
