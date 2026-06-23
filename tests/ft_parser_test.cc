#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsAFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}
