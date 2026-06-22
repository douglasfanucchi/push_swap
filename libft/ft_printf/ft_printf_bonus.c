/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:01:17 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:05:43 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	converter(int fd, const char **format, va_list args, int *counter);

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		counter;

	if (!format)
		return (0);
	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (converter(fd, &format, args, &counter) == FAIL)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format, fd);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}

static int	converter(int fd, const char **format, va_list args, int *counter)
{
	int				conversion_return;
	t_printf_info	info;

	init_specification_info(&info);
	if (setup_specification_info(format, counter, &info) == FAIL)
		return (FAIL);
	if (info.spec == '%' || info.spec == 'c')
		conversion_return = convert_c_and_percent(fd, &info, args);
	else if (info.spec == 's')
		conversion_return = convert_s(fd, &info, args);
	else if (info.spec == 'p')
		conversion_return = convert_p(fd, &info, args);
	else if (info.spec == 'd' || info.spec == 'i')
		conversion_return = convert_di(fd, &info, args);
	else if (info.spec == 'u')
		conversion_return = convert_u(fd, &info, args);
	else if (info.spec == 'f')
		conversion_return = convert_f(fd, args);
	else
		conversion_return = convert_x(fd, &info, args);
	if (conversion_return == FAIL)
		return (FAIL);
	*counter += conversion_return;
	return (*counter);
}
