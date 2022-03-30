/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_them_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:38:35 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:30:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_mlx_img(t_data *mlx)
{
	int	x;

	x = 0;
	while (x < 7)
		mlx_destroy_image(mlx->mlx, mlx->img[x++]);
	x = 0;
	free(mlx->img);
}

void	free_map(t_data *mlx)
{
	int	x;

	x = 0;
	while (mlx->map[x])
	{
		free(mlx->map[x]);
		mlx->map[x++] = NULL;
	}
	free(mlx->map);
	mlx->map = NULL;
}

void	free_them(t_data *mlx)
{
	free_mlx_img(mlx);
	free_map(mlx);
	free(mlx->buffer);
	free(mlx);
	ft_printf("You closed the game...");
	system("leaks so_long");
	exit(1);
}

void	free_for_map(t_data *mlx)
{
	free_map(mlx);
	free(mlx->buffer);
	mlx->buffer = NULL;
	free(mlx);
	ft_printf("Error\nWrong map...");
	system("leaks so_long");
	exit(1);
}

void	free_last(t_data *mlx)
{
	free_mlx_img(mlx);
	free_map(mlx);
	free(mlx->buffer);
	free(mlx);
	ft_printf("\nFinito...");
	system("leaks so_long");
	exit(1);
}
