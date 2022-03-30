/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:08:12 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 19:56:46 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*pos;

	i = 0;
	pos = lst;
	while (pos)
	{
		pos = pos->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *a,*b,*c;
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	c = (t_list *)malloc(sizeof(t_list));
	a->next = b;
	b->next =c;
	c->next = 0;
	printf("%d\n",ft_lstsize(a));
}*/
