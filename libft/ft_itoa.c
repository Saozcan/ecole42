/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:31:35 by saozcan           #+#    #+#             */
/*   Updated: 2022/01/09 01:24:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_total_number(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_calculate(int n, char *number, int tnum, int i)
{
	if (n < 0)
	{
		number[0] = '-';
		if (n == -2147483648)
		{
			n = -147483648;
			number [1] = '2';
		}	
		n *= -1;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			number [tnum - i - 1] = (unsigned char)((n % 10) + '0');
			n /= 10;
			i++;
		}
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		tnum;
	int		i;

	i = 0;
	tnum = ft_total_number(n);
	number = (char *)malloc(sizeof(char) * (tnum + 1));
	if (!number)
		return (0);
	number [0] = '0';
	number [tnum] = 0;
	number = ft_calculate(n, number, tnum, i);
	return (number);
}
/*
int	main(void)
{
	int i = -2147483648; 
	printf("%s\n", ft_itoa(i));
}*/
