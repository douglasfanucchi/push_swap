#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsAFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnFalseWhenStringIsNotAFlag) {
	const char *flag = "adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parse, itShouldReturnFalseWhenStringIsEmpty) {
	const char *flag = "";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}


TEST(ft_parse, itShouldReturnFalseWhenStringIsFlagButInvalid) {
	const char *flag = "--any_flag";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsAdaptativeFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsSimpleFlag) {
	const char *flag = "--simple";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsMediumFlag) {
	const char *flag = "--medium";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenStringIsComplexFlag) {
	const char *flag = "--complex";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenInputIsANumber) {
	const char *input = "42";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenInputIsANegativeNumber) {
	const char *input = "-42";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenInputIsPositiveSignedNumber) {
	const char *input = "+42";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_TRUE(result);
}

TEST(ft_parse, itShouldReturnFalseWhenInputHasMoreThanOneSign) {
	const char *input = "++42";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_FALSE(result);
}

TEST(ft_parse, itShouldReturnFalseWhenInputHasAnyNonNumericChar) {
	const char *input = "a42";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_FALSE(result);
}

TEST(ft_parse, itShouldReturnTrueWhenInputHasSpaceSeparatedNumbers) {
	const char *input = "            42        43              ";

	t_bool result = ft_is_valid_numeric_input(input);

	ASSERT_TRUE(result);
}
