/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <gucoelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:30:25 by gucoelho          #+#    #+#             */
/*   Updated: 2026/06/05 11:30:26 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		s_len;

	s_len = ft_strlen(s);
	new_string = (char *) malloc(s_len + 1);
	if (!new_string)
		return (NULL);
	ft_memmove (new_string, s, s_len + 1);
	return (new_string);
}
