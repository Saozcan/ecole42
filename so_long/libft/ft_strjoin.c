/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:51:09 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 18:23:41 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	char	*pos;

	if (!s1 || !s2)
		return (0);
	buff = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!buff)
		return (0);
	pos = buff;
	while (*s1)
		*buff++ = *s1++;
	while (*s2)
		*buff++ = *s2++;
	*buff = 0;
	return (pos);
}
/*
int	main(void)
{
	char a[] = "ahmet ";
	char b[] = "baba";
	printf("%s\n", ft_strjoin(a, b));
}*/
