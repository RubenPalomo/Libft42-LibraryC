/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpalomo- <rpalomo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:34:13 by rpalomo-          #+#    #+#             */
/*   Updated: 2022/08/08 18:18:18 by rpalomo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*check;
	void	*content;

	if (!f)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (content)
		{
			check = ft_lstnew(content);
			if (!check)
			{
				if (del)
					del(content);
				ft_lstclear(&dst, del);
				return (NULL);
			}
			ft_lstadd_back(&dst, check);
			lst = lst->next;
		}
	}
	return (dst);
}
