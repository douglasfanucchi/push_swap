#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_parser, itShouldNormalizeAnIntegerArray) {
	t_arr arr;
	arr.len = 7;
	arr.elements = malloc(sizeof(int) * 7);
	ft_memmove(arr.elements, (int[]){1, 2, 3, 42, -100, 2147483647, -2147483648}, 7 * sizeof(int));

	t_arr normalized = ft_normalize_int_arr(&arr);

	ASSERT_EQ(2, ((int *)normalized.elements)[0]);
	ASSERT_EQ(3, ((int *)normalized.elements)[1]);
	ASSERT_EQ(4, ((int *)normalized.elements)[2]);
	ASSERT_EQ(5, ((int *)normalized.elements)[3]);
	ASSERT_EQ(1, ((int *)normalized.elements)[4]);
	ASSERT_EQ(6, ((int *)normalized.elements)[5]);
	ASSERT_EQ(0, ((int *)normalized.elements)[6]);

	free(normalized.elements);
	free(arr.elements);
}
