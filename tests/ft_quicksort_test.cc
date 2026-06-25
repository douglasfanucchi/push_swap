#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_quicksort, itShouldSortAnIntegerArray) {
	t_arr arr;
	arr.len = 7;
	arr.elements = malloc(sizeof(int) * 7);
	ft_memmove(arr.elements, (int[]){1, 2, 3, 42, -100, 2147483647, -2147483648}, 7 * sizeof(int));

	ft_quicksort(arr, sizeof(int), ft_less_than_int, ft_swap_int);

	int *numbers = (int *)arr.elements;
	ASSERT_EQ(-2147483648, numbers[0]);
	ASSERT_EQ(-100, numbers[1]);
	ASSERT_EQ(1, numbers[2]);
	ASSERT_EQ(2, numbers[3]);
	ASSERT_EQ(3, numbers[4]);
	ASSERT_EQ(42, numbers[5]);
	ASSERT_EQ(2147483647, numbers[6]);

	free(arr.elements);
}

TEST(ft_quicksort, itShouldSortAnArrayOfPairsBasedOnTheSecondValueOfThePair) {
	int numbers[] = {1, 2, 3, 42, -100, 2147483647, -2147483648};
	t_arr arr;
	arr.len = 7;
	arr.elements = malloc(sizeof(int *) * 7);
	int	**pairs = (int **)arr.elements;
	for(int i = 0; i < 7; i++) {
		pairs[i] = (int *)malloc(sizeof(int) * 2);
		pairs[i][0] = i;
		pairs[i][1] = numbers[i];
	}

	ft_quicksort(arr, sizeof(int *), ft_less_than_pair, ft_swap_pair);

	ASSERT_EQ(-2147483648, pairs[0][1]);
	ASSERT_EQ(-100, pairs[1][1]);
	ASSERT_EQ(1, pairs[2][1]);
	ASSERT_EQ(2, pairs[3][1]);
	ASSERT_EQ(3, pairs[4][1]);
	ASSERT_EQ(42, pairs[5][1]);
	ASSERT_EQ(2147483647, pairs[6][1]);

	for(int i = 0; i < 7; i++)
		free(((int **)arr.elements)[i]);
	free(arr.elements);
}
