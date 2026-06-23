#include "push_swap.h"

static t_bool	ft_is_flag(const char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

t_bool	ft_is_valid_flag(const char *str)
{
	char	**options;

	options = (char *[]){
		"--adaptative",
		"--simple",
		"--medium",
		"--complex",
		NULL
	};
	if (!ft_is_flag(str))
		return (FALSE);
	while (*options)
	{
		if (ft_strcmp(str, *options) == 0)
			return (TRUE);
		options++;
	}
	return (FALSE);
}
