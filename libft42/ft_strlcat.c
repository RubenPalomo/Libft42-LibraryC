/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpalomo- <rpalomo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:39:48 by rpalomo-          #+#    #+#             */
/*   Updated: 2022/09/18 13:59:29 by rpalomo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
