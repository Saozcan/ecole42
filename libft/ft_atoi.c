/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:29:28 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 13:32:10 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long	res;
	long	resx;
	size_t	len;

	res = 0;
	resx = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			resx *= -1;
		str++;
	}
	len = ft_strlen(str);
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str++ - '0');
		if ((res * resx) > INT_MAX)
			return (-1);
		else if ((res * resx) < INT_MIN)
			return (0);
	}
	return ((int)res * (int)resx);
}
/*
int	main(void)
{
	char a[] = "    +1234";
	printf("%d\n", ft_atoi(a));
}*/
