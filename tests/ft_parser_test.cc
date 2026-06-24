#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsAFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenStringIsNotAFlag) {
	const char *flag = "adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenStringIsEmpty) {
	const char *flag = "";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}


TEST(ft_parser, itShouldReturnFalseWhenStringIsFlagButInvalid) {
	const char *flag = "--any_flag";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsAdaptativeFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsSimpleFlag) {
	const char *flag = "--simple";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsMediumFlag) {
	const char *flag = "--medium";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsComplexFlag) {
	const char *flag = "--complex";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenStringIsBenchFlag) {
	const char *flag = "--bench";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputIsANumber) {
	const char *input = "42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputIsANegativeNumber) {
	const char *input = "-42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputIsPositiveSignedNumber) {
	const char *input = "+42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputHasMoreThanOneSign) {
	const char *input = "++42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputHasAnyNonNumericChar) {
	const char *input = "a42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputHasSpaceSeparatedNumbers) {
	const char *input = "            42        43              ";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputIsEmpty) {
	const char *input = "";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputIsGreaterThanMaximumInteger) {
	const char *input = "2147483648";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}


TEST(ft_parser, itShouldReturnFalseWhenInputIsLessThanMinimumInteger) {
	const char *input = "-2147483649";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputHasDuplicatedNumbers) {
	const char **input;
	input = (const char *[]){
		"1 2 42",
		"42"
	};

	t_bool result = ft_has_duplicated_numbers(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputDoesNotHaveDuplicatedNumbers) {
	const char **input;
	input = (const char *[]){
		"1 2 42",
		"5"
	};

	t_bool result = ft_has_duplicated_numbers(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnFalseWhenInputIsNotAFlag) {
	const char *input = "any_text";

	t_bool result = ft_is_flag(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser, itShouldReturnTrueWhenInputIsAFlag) {
	const char *input = "--any_flag";

	t_bool result = ft_is_flag(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser, itShouldUpdateBenchStateInTheProgramWhenFlagIsBenchRelated) {
	const char *input = "--bench";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(TRUE, program.bench);
}
