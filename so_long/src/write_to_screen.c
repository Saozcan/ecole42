/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:22:40 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/23 16:57:36 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_total_move(t_data *mlx)
{
	char	*a;

	a = ft_itoa(mlx->count);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 20, 20, 0xffffff, "Your Score: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 120, 20, 0xffffff, a);
	free(a);
	a = ft_itoa(mlx->move_count);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 300, 20, 0xffffff, "Total Moves: ");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 400, 20, 0xffffff, a);
	free(a);
}
