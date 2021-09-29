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

#include "../includes/so_long.h"

void	ft_static_images(char key, t_windows *win)
{
	t_image *img;

	if (key == '1')
		img->img = mlx_xpm_file_to_image(win->mlx, img->img_1, \
											&img->img_h, &img->img_w);
	if (key == '0')
		img->img = mlx_xpm_file_to_image(win->mlx, img->img_0, \
											&img->img_h, &img->img_w);
	if (key == 'C')
		img->img = mlx_xpm_file_to_image(win->mlx, img->img_C, \
											&img->img_h, &img->img_w);
	if (key == 'E')
		img->img = mlx_xpm_file_to_image(win->mlx, img->img_E, \
											&img->img_h, &img->img_w);
}

void	ft_main_character(char key, t_windows *win)
{
	t_image *img;

	if (key == 'P')
		img->img = mlx_xpm_file_to_image(win->mlx, img->img_character, \
											&img->img_h, &img->img_w);
}

void	ft_put_image(char key, t_windows *win, int y, int x)
{
	t_image *img;

	if (key == '1' || key == '0' || key == 'C' || key == 'E')
		ft_static_images(key, win);
	if (key == 'P')
	{
		win->pos_x = x;
		win->pos_y = y;
	}
		ft_main_character(key, win);
	mlx_put_image_to_window(win->mlx, win->win, img->img, \
								x * img->img_h, y * img->img_w);
}

int	ft_animation(t_windows *win)
{
	int	w;
	int	l;

	w = 0;
	if ((double)(clock()) / CLOCKS_PER_SEC - win->time >= (double)1 / 10)
	{
		win->frame++;
		win->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (win->frame > 49)
		win->frame = 0;
	while (win->map[w])
	{
		l = 0;
		while (win->map[w][l])
		{
			if (win->map[w][l] == 'D' && win->frame > 24)
				ft_put_image('D', win, w, l);
			else if (win->map[w][l] == 'D' && win->frame <= 24)
				ft_put_image('X', win, w, l);
			l++;
		}
		w++;
	}
	return (0);
}