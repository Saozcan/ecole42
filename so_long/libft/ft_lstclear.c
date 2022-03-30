/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:13:02 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 19:55:16 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	while (*lst)
	{
		pos = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pos;
	}
	*lst = 0;
}

/*
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *secpos;

	pos = *lst;
	if (!lst || !del)
		return;
	while (pos)
	{
		secpos = pos->next;
		ft_lstdelone(pos, del);
		pos = secpos;
	}
}*/
/*
void	ft_del_list(void *s)
{
	unsigned char *str;

	str = s;
	ft_bzero(str, sizeof(str));
}

int	main(void)
{
	t_list *a,*b,*c,*d;
	t_list **ab;
	ab = (t_list **)malloc(sizeof(t_list *));
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	c = (t_list *)malloc(sizeof(t_list));
	d = (t_list *)malloc(sizeof(t_list));
	*ab = a;
	a->next = b;
	a->content = "a";
	b->next =c;
	c->next = 0;
	d->content = "whatsup";
	c->content = "merhaba";
	ft_lstclear(ab, ft_del_list);

	printf("%s\n",c->content);
}*/
