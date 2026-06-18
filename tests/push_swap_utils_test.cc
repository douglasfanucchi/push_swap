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
