/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:41:19 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 19:56:03 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buff;

	buff = (t_list *)malloc(sizeof(t_list) * 1);
	if (!buff)
		return (0);
	buff->content = content;
	buff->next = 0;
	return (buff);
}
