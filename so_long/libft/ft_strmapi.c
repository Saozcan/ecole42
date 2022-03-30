/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:14:39 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 01:14:43 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*

 char my_func(unsigned int i, char str)
 {
 	printf("My inner function: index = %d and %c\n", i, str);
 	return str - 32;
}

 int main()
 {
 	char str[10] = "hello.";
 	printf("The result is %s\n", str);
 	char *result = ft_strmapi(str, my_func);
 	printf("The result is %s\n", result);
return 0;

 }
*/
