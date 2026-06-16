/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:40:23 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/11 10:00:50 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft.h"

# ifndef HEXBASELOW
#  define HEXBASELOW "0123456789abcdef"
# endif

# ifndef HEXBASEUP
#  define HEXBASEUP "0123456789ABCDEF"
# endif

# ifndef DECIMALBASE
#  define DECIMALBASE "0123456789"
# endif

# ifndef EMPTY
#  define  EMPTY -1
# endif

# ifndef TRUE
#  define  TRUE 1
# endif

# ifndef FALSE
#  define  FALSE 0
# endif

# ifndef FAIL
#  define  FAIL -42
# endif

typedef struct s_printf_info
{
	unsigned int	alt;
	unsigned int	space;
	unsigned int	left;
	unsigned int	showsign;
	unsigned char	pad;
	long			width;
	long			prec;
	unsigned char	spec;
}	t_printf_info;

int		ft_printf(const char *format, ...);
void	init_specification_info(t_printf_info *info);
int		setup_specification_info(const char **format, int *counter, \
		t_printf_info *info);
int		convert_c_and_percent(t_printf_info *info, va_list args);
int		convert_s(t_printf_info *info, va_list args);
int		convert_p(t_printf_info *info, va_list args);
int		convert_di(t_printf_info *info, va_list args);
int		convert_u(t_printf_info *info, va_list args);
int		convert_x(t_printf_info *info, va_list args);
int		convert_f(va_list args);
int		ft_putnbr_base(unsigned long int nbr, char *base);
char	*ft_litoa_base(unsigned long int nbr, char *base);
char	*get_precision_diu(t_printf_info *info, char **str);
char	*get_precision_s(t_printf_info *info, char **str);
char	*get_precision_base(t_printf_info *info, char **str);
char	*get_width(t_printf_info *info, char **str);
int		width_edge_case(t_printf_info *info);
int		width_and_precision_handler(t_printf_info *info, char *str);
char	*ft_strjoin_free(char *s1, char **s2);

#endif
