/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:11:44 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 01:10:38 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l2;

	l2 = ft_strlen(needle);
	if (!l2)
		return ((char *)haystack);
	while (*haystack && len-- >= l2)
	{
		if (!ft_memcmp(haystack, needle, l2))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
/*
int	main(void)
{
	char *a = "merhaba";
	char *b = "hab";

	printf ("%s\n", ft_strnstr(a, b, 3));
}*/
