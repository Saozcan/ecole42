/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:46:45 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 19:46:41 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	main(int ac, char **av)
{
	t_data	*mlx_data;

	if (ac != 2)
		return (0);
	mlx_data = (t_data *)calloc(sizeof(t_data), 1);
	if (!mlx_data)
		error_mlx_data(0);
	check_map(av[1], mlx_data);
	mlx_data->mlx = mlx_init();
	make_imgs(mlx_data);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, mlx_data->width * 64, \
	mlx_data->height * 64, "Welcome Bro...");
	mlx_data->character = mlx_data->img[1];
	replace_map(mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 0, ft_close, mlx_data);
	mlx_hook(mlx_data->mlx_win, 17, 1L << 2, ft_close_all, mlx_data);
	mlx_loop(mlx_data->mlx);
	return (0);
}
