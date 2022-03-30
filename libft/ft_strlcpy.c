/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:07 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 20:00:18 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	len;

	size = ft_strlen(src);
	len = 0;
	if (dstsize > 0)
	{
		while (src[len] && len < (dstsize - 1))
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (size);
}
