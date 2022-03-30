/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:36:34 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:49:35 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	for_player(t_data *mlx, int i)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->character, \
	mlx->x, mlx->y);
	mlx->index = i;
}

void	replace_map(t_data *mlx)
{
	mlx->w1 = 0;
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->buffer[mlx->w1])
	{
		if (mlx->buffer[mlx->w1] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img[0], \
			mlx->x, mlx->y);
		else if (mlx->buffer[mlx->w1] == 'P')
			for_player(mlx, mlx->w1);
		else if (mlx->buffer[mlx->w1] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img[5], \
			mlx->x, mlx->y);
		else if (mlx->buffer[mlx->w1] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img[6], \
			mlx->x, mlx->y);
		else if (mlx->buffer[mlx->w1] == '\n')
		{
				mlx->y += 64;
				mlx->x = -64;
		}
		mlx->x += 64;
		mlx->w1++;
		write_total_move(mlx);
	}
}

void	make_imgs(t_data *mlx_data)
{
	mlx_data->img = (void **)malloc(sizeof(void *) * 7);
	if (!mlx_data->img)
		error_mlx_img(mlx_data);
	mlx_data->img[0] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/wall.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[1] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/face.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[2] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/right.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[3] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/left.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[4] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/behind.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[5] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/my_girl.xpm", &mlx_data->w1, &mlx_data->h1);
	mlx_data->img[6] = mlx_xpm_file_to_image(mlx_data->mlx, \
	"./assets/collectiable.xpm", &mlx_data->w1, &mlx_data->h1);
}

/* int	main(int ac, char **av)
{
	t_data	*mlx_data;

	(void)ac;
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
 */