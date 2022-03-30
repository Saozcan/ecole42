/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:25:26 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/22 03:23:36 by saozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;

	a.type = 'a';
	b.type = 'b';
	if (ac == 2)
		for_two_args(av[1], &a, &b);
	else if (ac > 2 && ac <= 502)
		for_more_args(ac, av, &a, &b);
	else
		return (0);
	check_double(&a, &b);
	indexing(&a);
	check_listed(&a, &b);
	if (a.size > 5)
		sort_the_list(&a, &b);
	else
		sort_smaller_list(&a, &b);
	free(a.array);
	free(b.array);
	return (0);
}
