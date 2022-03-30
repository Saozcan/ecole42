/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:43:01 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 14:10:46 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pos;
	t_list	*buff;

	pos = 0;
	while (lst)
	{
		buff = ft_lstnew(f(lst->content));
		if (!buff)
		{
			ft_lstclear(&pos, del);
			return (0);
		}
		ft_lstadd_back(&pos, buff);
		lst = lst->next;
	}
	return (pos);
}
