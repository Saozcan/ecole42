/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:51:57 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:30:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	char_count(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

void	check_walls(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[0][i] == '1')
		i++;
	if (i != mlx->width)
		free_for_map(mlx);
	i = 0;
	while (mlx->map[i] && (mlx->map[i][0] == '1' && \
	mlx->map[i][mlx->width - 1] == '1'))
		i++;
	if (i != mlx->height)
		free_for_map(mlx);
	i = 0;
	while (mlx->map[mlx->height - 1][i] == '1')
		i++;
	if (i != mlx->width)
		free_for_map(mlx);
}

void	check_chars(t_data *mlx)
{
	char	*s;
	int		p;
	int		c;
	int		e;
	int		b;

	p = 0;
	c = 0;
	e = 0;
	b = 0;
	s = mlx->buffer;
	while (*s)
	{
		if (*s == 'P')
			p++;
		else if (*s == 'C')
			c++;
		else if (*s == 'E')
			e++;
		else if (*s == 'B')
			b++;
		s++;
	}
	if (!(p == 1 && c > 1 && e == 1))
		free_for_map(mlx);
}

void	map_h_w_check(char *s, t_data *mlx)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(s, O_RDONLY);
	mlx->buffer = malloc(2001);
	if (!mlx->buffer)
		error_buff(mlx);
	i = read(fd, mlx->buffer, 2000);
	mlx->buffer[i] = '\0';
}

void	check_map(char *s, t_data *mlx)
{
	int		width;
	int		height;
	int		i;

	map_h_w_check(s, mlx);
	mlx->map = ft_split(mlx->buffer, '\n');
	if (!mlx->map)
		error_map(mlx);
	width = ft_strlen(*mlx->map);
	height = 0;
	while (mlx->map[height])
		height++;
	i = 1;
	while (mlx->map[i])
	{
		if (ft_strlen(mlx->map[i]) != (unsigned long)width)
			free_for_map(mlx);
		i++;
	}
	mlx->width = width;
	mlx->height = height;
	check_walls(mlx);
	check_chars(mlx);
}
