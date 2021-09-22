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

#include "../includes/so_long.h"

void	ft_move(t_windows *win, int x, int y)
{
	win->map[win->pos_y][win->pos_x] = '0';
	put_image('0', win, win->pos_y, win->pos_x);
	win->map[win->pos_y + y][win->pos_x + x] = 'P';
	put_image('P', win, win->pos_y + y, win->pos_x + x);
	win->move++;
	step_printer(win);
}