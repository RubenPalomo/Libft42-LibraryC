/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpalomo- <rpalomo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:20:55 by rpalomo-          #+#    #+#             */
/*   Updated: 2022/08/15 16:46:19 by rpalomo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
		free(ptr);
	}
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	size_t	count;
	size_t	size;
	char	*ptr;

	count = 1860000000007407000;
	size = 0;
	ptr = ft_calloc(count, size);
	printf("dirección = %p\nvalor = %s", &ptr, ptr);
	return (0);
}*/
