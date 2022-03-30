/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:14:47 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/15 10:28:34 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_itoa(int nbr)
{
	if (nbr > 9)
		ft_itoa(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}
/*
void	read_char(int i)
{
	static char	character = 0;
	static int	j = 128;

	if (i)
		character += j;
	j /= 2;
	if (j == 0)
	{
		ft_putchar(character);
		j = 128;
		character = 0;
	}
	usleep(200);
}*/
/*
void	read_char(int i)
{
	static char	character = 0;
	static int	j = 7;
	character += (i << j);
	if (j == 0)
	{
		ft_putchar(character);
		j = 8;
		character = 0;
	}
	j--;
	usleep(200);
}
*/

void	read_char(int i)
{
	static char	character = 0;
	static int	j = 0;

	character += (i << j);
	if (j == 7)
	{
		ft_putchar(character);
		j = -1;
		character = 0;
	}
	j++;
	usleep(200);
}

void	read_signals(int sig)
{
	if (sig == SIGUSR1)
		read_char(1);
	else if (sig == SIGUSR2)
		read_char(0);
}

int	main(void)
{
	signal(SIGUSR1, read_signals);
	signal(SIGUSR2, read_signals);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
