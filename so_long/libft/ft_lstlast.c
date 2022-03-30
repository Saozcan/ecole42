/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:18:16 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 19:57:11 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
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
	c->content = "merhaba";
	printf("%s\n",ft_lstlast(a)->content);
}
*/
