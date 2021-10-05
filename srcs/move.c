/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:31:57 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 12:31:57 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_action_move(t_windows *win, int x, int y)
{
	win->map[win->pos_y][win->pos_x] = '0';
	ft_put_image('0', win, win->pos_y, win->pos_x);
	win->map[win->pos_y + y][win->pos_x + x] = 'P';
	ft_put_image('P', win, win->pos_y + y, win->pos_x + x);
	win->move++;
	ft_printer(win);
}

void	ft_move(t_windows *win, int x, int y)
{
	if (win->map[win->pos_y + y][win->pos_x + x] != '1')
	{
		if (win->map[win->pos_y + y][win->pos_x + x] == 'E' \
				&& win->collect == 0)
			ft_close(win, 'W');
		else if (win->map[win->pos_y + y][win->pos_x + x] == 'C')
		{
			ft_action_move(win, x, y);
			win->collect -= 1;
			if (win->collect == 0)
				ft_exit(win);
		}
		else if (win->map[win->pos_y + y][win->pos_x + x] == '0')
			ft_action_move(win, x, y);
	}
}

int	ft_push(int key, t_windows *win)
{
	if (key == 13)
		ft_move(win, 0, -1);
	else if (key == 1)
		ft_move(win, 0, 1);
	else if (key == 0)
		ft_move(win, -1, 0);
	else if (key == 2)
		ft_move(win, 1, 0);
	else if (key == 53)
		ft_close(win, 'C');
	return (0);
}
