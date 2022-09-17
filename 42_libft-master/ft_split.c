/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpalomo- <rpalomo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:23:15 by rpalomo-          #+#    #+#             */
/*   Updated: 2022/08/06 18:59:06 by rpalomo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_parts(const char *s, char c)
{
	int	i;
	int	parts;

	parts = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && !(s[i] == c || s[i] == '\0'))
			parts++;
		i++;
	}
	return (parts);
}

static void	ft_write_part(char **split, const char *s_part, char c, int part)
{
	int	i;

	i = 0;
	while (!(s_part[i] == c || s_part[i] == '\0'))
	{
		split[part][i] = s_part[i];
		i++;
	}
	split[part][i] = '\0';
}

static int	ft_alloc_mem(char **split, int j, int part)
{
	split[part] = (char *)malloc(sizeof(char) * (j + 1));
	if (!split[part])
	{
		while (part > 0)
			free(split[--part]);
		free(split);
		return (0);
	}
	return (1);
}

static int	ft_write_split(char **split, const char *s, char c, int parts)
{
	int		i;
	int		j;
	int		part;

	part = 0;
	i = 0;
	while (s[i] && part < parts)
	{
		if (s[i] == c || s[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (!(s[i + j] == c || s[i + j] == '\0'))
				j++;
			if (ft_alloc_mem(split, j, part) == 0)
				return (0);
			ft_write_part(split, s + i, c, part);
			i = i + j;
			part++;
		}
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		parts;

	if (!s)
		return (NULL);
	parts = ft_count_parts(s, c);
	split = (char **)malloc(sizeof(char *) * (parts + 1));
	if (!split)
		return (NULL);
	split[parts] = 0;
	if (ft_write_split(split, s, c, parts) == 0)
		return (NULL);
	return (split);
}

/*int  main()
{
	char **dest;
	char P[] = "   hola papu que  tal   ";
	char U = ' ';
	int	i = 0;

	printf("%s\n", P);
	dest = ft_split(P, U);
	while (dest[i])
	{
		printf("part = %d -> %s \n", i, dest[i]);
		i++;
	}
	return (0);
}*/
