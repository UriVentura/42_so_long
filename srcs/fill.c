/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:19:34 by oventura          #+#    #+#             */
/*   Updated: 2021/09/28 15:19:34 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_static_images(char key, t_windows *win)
{
	if (key == '1')
		win->img = mlx_xpm_file_to_image(win->mlx, win->img_1, \
											&win->img_h, &win->img_w);
	if (key == '0')
		win->img = mlx_xpm_file_to_image(win->mlx, win->img_0, \
											&win->img_h, &win->img_w);
	if (key == 'C')
		win->img = mlx_xpm_file_to_image(win->mlx, win->img_coin, \
											&win->img_h, &win->img_w);
	if (key == 'E')
		win->img = mlx_xpm_file_to_image(win->mlx, win->img_exit, \
											&win->img_h, &win->img_w);
}

void	ft_main_character(char key, t_windows *win)
{
	if (key == 'P')
		win->img = mlx_xpm_file_to_image(win->mlx, win->img_character, \
											&win->img_h, &win->img_w);
}

void	ft_put_image(char key, t_windows *win, int y, int x)
{
	if (key == '1' || key == '0' || key == 'C' || key == 'E')
		ft_static_images(key, win);
	if (key == 'P')
	{
		win->pos_x = x;
		win->pos_y = y;
	}
	ft_main_character(key, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, \
								x * win->img_h, y * win->img_w);
}

void	ft_exit(t_windows *win)
{
	int	w;
	int	h;

	w = 0;
	while (win->map[w])
	{
		h = 0;
		while (win->map[w][h])
		{
			if (win->map[w][h] == 'E')
				ft_put_image('E', win, w, h);
			h++;
		}
		w++;
	}
}
