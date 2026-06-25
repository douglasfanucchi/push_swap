#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputIsNotAFlag) {
	const char *input = "any_text";

	t_bool result = ft_is_flag(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputIsAFlag) {
	const char *input = "--any_flag";

	t_bool result = ft_is_flag(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsAFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenStringIsNotAFlag) {
	const char *flag = "adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenStringIsEmpty) {
	const char *flag = "";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}


TEST(ft_parser_utils, itShouldReturnFalseWhenStringIsFlagButInvalid) {
	const char *flag = "--any_flag";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsAdaptativeFlag) {
	const char *flag = "--adaptative";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsSimpleFlag) {
	const char *flag = "--simple";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsMediumFlag) {
	const char *flag = "--medium";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsComplexFlag) {
	const char *flag = "--complex";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenStringIsBenchFlag) {
	const char *flag = "--bench";

	t_bool result = ft_is_valid_flag(flag);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputIsANumber) {
	const char *input = "42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputIsANegativeNumber) {
	const char *input = "-42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputIsPositiveSignedNumber) {
	const char *input = "+42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputHasMoreThanOneSign) {
	const char *input = "++42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputHasAnyNonNumericChar) {
	const char *input = "a42";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputHasSpaceSeparatedNumbers) {
	const char *input = "            42        43              ";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputIsEmpty) {
	const char *input = "";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputIsGreaterThanMaximumInteger) {
	const char *input = "2147483648";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}


TEST(ft_parser_utils, itShouldReturnFalseWhenInputIsLessThanMinimumInteger) {
	const char *input = "-2147483649";

	t_bool result = ft_is_valid_numeric_set(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldReturnTrueWhenInputHasDuplicatedNumbers) {
	const char *input[] = {
		"1 2 42",
		"42",
		NULL
	};

	t_bool result = ft_has_duplicated_numbers(input);

	ASSERT_TRUE(result);
}

TEST(ft_parser_utils, itShouldReturnFalseWhenInputDoesNotHaveDuplicatedNumbers) {
	const char *input[] = {
		"1 2 42",
		"5",
		NULL
	};

	t_bool result = ft_has_duplicated_numbers(input);

	ASSERT_FALSE(result);
}

TEST(ft_parser_utils, itShouldUpdateBenchStateInTheProgramWhenFlagIsBenchRelated) {
	const char *input = "--bench";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(TRUE, program.bench);
}

TEST(ft_parser_utils, itShouldSetStrategyAsAdaptativeWhenInputIsAdaptativeFlag) {
	const char *input = "--adaptative";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(adaptative, program.strategy);
}

TEST(ft_parser_utils, itShouldSetStrategyAsSimpleWhenInputIsSimpleFlag) {
	const char *input = "--simple";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(simple, program.strategy);
}

TEST(ft_parser_utils, itShouldSetStrategyAsMediumWhenInputIsMediumFlag) {
	const char *input = "--medium";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(medium, program.strategy);
}

TEST(ft_parser_utils, itShouldSetStrategyAsComplexWhenInputIsComplexFlag) {
	const char *input = "--complex";
	t_program	program;

	ft_program_flag_update(input, &program);

	ASSERT_EQ(complex, program.strategy);
}
