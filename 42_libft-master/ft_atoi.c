/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpalomo- <rpalomo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:05:33 by rpalomo-          #+#    #+#             */
/*   Updated: 2022/09/18 12:04:52 by rpalomo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_spaces(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_number(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				is_neg;

	res = 0;
	i = 0;
	is_neg = 1;
	while (ft_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			is_neg = -1;
	while (ft_number(str[i]) != -1)
	{
		res = res * 10 + ft_number(str[i]);
		if (res > (~0UL >> 1) && is_neg == 1)
			return (-1);
		else if (res > (~0UL >> 1) && is_neg == -1)
			return (0);
		i++;
	}
	return (res * is_neg);
}
