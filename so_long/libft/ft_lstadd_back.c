/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:28:05 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 20:54:21 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pos = ft_lstlast(*lst);
	pos->next = new;
}
/*
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
	ft_lstadd_back(ab, d);

	printf("%s\n",c->next->content);
}
*/
