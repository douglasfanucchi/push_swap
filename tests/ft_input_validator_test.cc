#include <gtest/gtest.h>

extern "C" {
    #include "push_swap.h"
}

TEST(ft_input_validator, itShouldReturnTrueWhenInputIsJustAValidSetOfNumbers) {
    const char *argv[] = {
        "push_swap",
        "1",
        "3 100 -10",
        "-2147483648 2147483647",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_TRUE(result);
}

TEST(ft_input_validator, itShouldReturnFalseWhenInputHasDuplicatedNumber) {
    const char *argv[] = {
        "push_swap",
        "1",
        "3 100 -10",
        "-2147483648 2147483647 1",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_FALSE(result);
}

TEST(ft_input_validator, itShouldReturnFalseWhenInputHasNumbersOutOfRange) {
    const char *argv[] = {
        "push_swap",
        "1",
        "3 100 -10",
        "-2147483648 2147483670",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_FALSE(result);
}

TEST(ft_input_validator, itShouldReturnFalseWhenInputHasNonNumericValue) {
    const char *argv[] = {
        "push_swap",
        "1",
        "3 100 -10",
        "-2147483648 hello",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_FALSE(result);
}

TEST(ft_input_validator, itShouldReturnTrueWhenInputHasValidFlagsAndValidNumbers) {
    const char *argv[] = {
        "push_swap",
        "--adaptative",
        "1",
        "3 100 -10",
        "-2147483648",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_TRUE(result);
}

TEST(ft_input_validator, itShouldReturnFalseWhenInputHasInvalidFlags) {
    const char *argv[] = {
        "push_swap",
        "--any_flag",
        "1",
        "3 100 -10",
        "-2147483648",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_FALSE(result);
}

TEST(ft_input_validator, itShouldReturnFalseWhenInputHasNoFlagsOrNumbers) {
    const char *argv[] = {
        "push_swap",
        "hello world",
        NULL
    };

    t_bool result = ft_input_validator(argv + 1);

    ASSERT_FALSE(result);
}
