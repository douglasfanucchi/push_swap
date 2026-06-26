#include "push_swap.h"

t_bool  ft_input_validator(const char **input)
{
    const char  **numbers;

    while (*input && ft_is_flag(*input))
    {
        if (!ft_is_valid_flag(*input))
            return (FALSE);
        input++;
    }
    if (!*input)
        return (FALSE);
    numbers = input;
    while (*input)
    {
        if (!ft_is_valid_numeric_set(*input))
            return (FALSE);
        input++;
    }
    if (ft_has_duplicated_numbers(numbers))
        return (FALSE);
    return (TRUE);
}
