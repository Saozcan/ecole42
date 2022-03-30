/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:58 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/12 21:12:01 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (0);
	j = 0;
	i = start;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *buffer;
	size_t i;
	size_t lens;
	
	i = 0;
	if (len == 0 || !s)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	s += start;
	lens = ft_strlen(s);
	while (i < len && s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}*/
/*
int	main(void)
{
	char a[] = "ahmet";

	printf("%s\n", ft_substr(a, 1, 1));
}*/
