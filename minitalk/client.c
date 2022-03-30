/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:13:18 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/15 10:23:38 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *s)
{
	int	count;
	int	times;
	int	i;

	i = 0;
	times = 1;
	count = 0;
	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		count += times * (s[i] - 48);
		times *= 10;
		i--;
	}
	return (count);
}
/*
void	send_characters(char *s, int portn)
{
	while (*s)
	{
		int i;

		i = 128;
		while (i >= 1)
		{
			if (*s / i)
			{
				*s -= i;
				kill(portn, SIGUSR1);
			}
			else
				kill(portn, SIGUSR2);
			i /= 2;
			usleep(200);
		}
		s++;
	}
}*/
/*
void	send_characters(char *s, int portn)
{
	while (*s)
	{
		int i;

		i = 7;
		while (i >= 0)
		{
			if (*s & (1 << i))
				kill(portn, SIGUSR1);
			else
				kill(portn, SIGUSR2);
			i--;
			usleep(200);
		}
		s++;
	}
}
*/

void	send_characters(char *s, int portn)
{
	int	i;

	while (*s)
	{
		i = 0;
		while (i <= 7)
		{
			if (*s & (1 << i))
				kill(portn, SIGUSR1);
			else
				kill(portn, SIGUSR2);
			i++;
			usleep(200);
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	send_characters(av[2], ft_atoi(av[1]));
	write(1, "\n", 1);
}
