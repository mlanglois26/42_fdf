/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:27:39 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/21 10:47:44 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	is_valid(char c, int base)
{
	char	*s1;
	char	*s2;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	while (base--)
	{
		if (s1[base] == c || s2[base] == c)
			return (1);
	}
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (is_valid(str[i], str_base))
	{
		res = res * str_base + value_of(str[i]);
		i++;
	}
	return (res);
}
