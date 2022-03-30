/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:58:42 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:42:03 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_left(t_data *mlx)
{
	if (mlx->buffer[mlx->index - 1] == 'C')
		mlx->count++;
	else if (mlx->buffer[mlx->index - 1] == 'E')
		finally_my_girl(mlx);
	mlx->character = mlx->img[3];
	mlx->buffer[mlx->index] = '0';
	mlx->buffer[mlx->index - 1] = 'P';
	mlx->move_count++;
	ft_printf("Total move: %d\n", mlx->move_count);
}

void	go_down(t_data *mlx)
{
	if (mlx->buffer[mlx->index + mlx->index + 1] == 'C')
		mlx->count++;
	else if (mlx->buffer[mlx->index - 1] == 'E')
		finally_my_girl(mlx);
	mlx->character = mlx->img[1];
	mlx->buffer[mlx->index] = '0';
	mlx->buffer[mlx->index + mlx->width + 1] = 'P';
	mlx->move_count++;
	ft_printf("Total move: %d\n", mlx->move_count);
}

void	go_right(t_data *mlx)
{
	if (mlx->buffer[mlx->index + 1] == 'C')
		mlx->count++;
	else if (mlx->buffer[mlx->index - 1] == 'E')
		finally_my_girl(mlx);
	mlx->character = mlx->img[2];
	mlx->buffer[mlx->index] = '0';
	mlx->buffer[mlx->index + 1] = 'P';
	mlx->move_count++;
	ft_printf("Total move: %d\n", mlx->move_count);
}

void	go_up(t_data *mlx)
{
	if (mlx->buffer[mlx->index - mlx->index - 1] == 'C')
		mlx->count++;
	else if (mlx->buffer[mlx->index - 1] == 'E')
		finally_my_girl(mlx);
	mlx->character = mlx->img[4];
	mlx->buffer[mlx->index] = '0';
	mlx->buffer[mlx->index - mlx->width - 1] = 'P';
	mlx->move_count++;
	ft_printf("Total move: %d\n", mlx->move_count);
}

int	ft_close(int keycode, t_data *mlx)
{
	if (keycode == 0 && mlx->buffer[mlx->index - 1] != '1')
		go_left(mlx);
	else if (keycode == 1 && mlx->buffer[mlx->index + mlx->width + 1] != '1')
		go_down(mlx);
	else if (keycode == 2 && mlx->buffer[mlx->index + 1] != '1')
		go_right(mlx);
	else if (keycode == 13 && mlx->buffer[mlx->index - mlx->width - 1] != '1')
		go_up(mlx);
	else if (keycode == 53)
	{
		free_them(mlx);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit (1);
	}
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	replace_map(mlx);
	return (0);
}
