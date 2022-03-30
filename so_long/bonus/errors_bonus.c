/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:08:38 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:30:15 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	error_mlx_data(int i)
{
	(void)i;
	ft_printf("Error\nMalloc does not working(t_data)...");
	exit(1);
}

void	error_mlx_img(t_data *mlx)
{
	free(mlx);
	ft_printf("Error\nMalloc does not working(imgs)...");
	exit(1);
}

void	error_buff(t_data *mlx)
{
	free_mlx_img(mlx);
	free(mlx);
	ft_printf("Error\nMalloc does not working(buff)...");
	exit(1);
}

void	error_map(t_data *mlx)
{
	free_mlx_img(mlx);
	free(mlx->buffer);
	free(mlx);
	ft_printf("Error\nMalloc does not working(split)...");
	exit(1);
}
