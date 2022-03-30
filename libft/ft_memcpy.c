/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:16:56 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 10:06:44 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*pos;

	if (!dst && !src)
		return (0);
	pos = dst;
	while (n--)
	{
		*(char *)dst++ = *(char *)src++;
	}
	return (pos);
}
