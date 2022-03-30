/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:23:10 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 01:03:24 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;

	dest = b;
	while (len > 0)
	{
		*dest++ = (unsigned char)c;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char a[] = "mehmet";

	ft_memset(a, 'x', 3);
	printf("%s\n", a);
}*/
