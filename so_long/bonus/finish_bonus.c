/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:45:13 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:30:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_all(t_data *mlx)
{
	free_them(mlx);
	return (0);
}

int	to_close(int keycode, t_data *mlx)
{
	if (keycode == 53)
	{
		free_last(mlx);
		exit(1);
	}
	return (0);
}

void	finally_my_girl(t_data *mlxx)
{
	void	*mlx;
	void	*mlx_win;
	char	*a;

	mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
	mlxx->w1 = open("./src/last_message", O_RDONLY);
	mlxx->h1 = read(mlxx->w1, mlxx->buffer, 2000);
	mlxx->buffer[mlxx->h1] = '\0';
	ft_printf("%s\n", mlxx->buffer);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 512, 512, "Hello world!");
	mlx_string_put(mlx, mlx_win, 180, 200, 0xffffff, "Your Score: ");
	a = ft_itoa(mlxx->count);
	mlx_string_put(mlx, mlx_win, 260, 200, 0xffffff, a);
	mlx_string_put(mlx, mlx_win, 180, 250, 0xffffff, "game over bro...");
	mlx_hook(mlx_win, 2, 1L << 2, to_close, mlxx);
	mlx_hook(mlx_win, 17, 1L << 17, ft_close_all, mlxx);
	mlx_loop(mlx);
}
