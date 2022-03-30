/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:22:39 by saozcan           #+#    #+#             */
/*   Updated: 2022/02/24 18:25:41 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	**img;
	int		w1;
	int		h1;
	size_t	index;
	char	*buffer;
	void	*character;
	int		width;
	int		height;
	int		count;
	int		move_count;
	int		x;
	int		y;
	char	**map;
}t_data;

void	check_map(char *s, t_data *mlx);
void	free_them(t_data *mlx);
int		ft_close(int key_code, t_data *mlx);
void	replace_map(t_data *mlx);
void	finally_my_girl(t_data *mlx);
int		to_close_all(t_data *mlx);
void	free_for_map(t_data *mlx);
void	free_mlx_img(t_data *mlx);
void	free_map(t_data *mlx);
void	free_last(t_data *mlx);
void	error_mlx_data(int i);
void	error_mlx_img(t_data *mlx);
void	error_buff(t_data *mlx);
void	error_map(t_data *mlx);
void	free_mlx_map(t_data *mlx);
int		ft_close_all(t_data *mlx);
void	write_total_move(t_data *mlx);

#endif