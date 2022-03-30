/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:44:56 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 01:08:43 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	original;

	original = dstsize;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst++;
		dstsize--;
	}
	if (dstsize == 0)
		return (ft_strlen(src) + original);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (total);
}
/*
#include <string.h>

int	main(void)
{
	char a[] = "ahmet123123";
	char b[] = "bababbbb";

	//printf("%lu\n",strlcat(a, b, 12));
	printf("%lu\n",ft_strlcat(a, b, 14));
	printf("%s\n", a);
}*/
