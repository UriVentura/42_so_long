/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:06:50 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 10:06:50 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_fill(t_windows *fill)
{
	int	w;
	int	h;

	w = 0;
	while (fill->map[w])
	{
		h = 0;
		while (fill->map[w][h])
		{
			ft_put_image(fill->map[w][h], fill, w, h);
			h++;
		}
		w++;
	}
}

void	ft_init_game(t_windows *init)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, init->map_len * 64, \
								init->map_width * 64, "so long");
	ft_map_fill(init);
	mlx_hook(init->win, 2, 0, ft_push, init);
	mlx_hook(init->win, 17, 0, ft_close_x, init);
	mlx_loop(init->mlx);
}

void	ft_init_so_long(char *map)
{
	t_windows	init;

	ft_init_struct(&init);
	ft_map_count(map, &init);
	ft_map_parse(map, &init);
	ft_checker(&init);
	ft_init_game(&init);
}
