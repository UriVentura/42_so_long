/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:00:01 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 10:00:01 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_printer(t_windows *move)
{
	char	*count;

	count = ft_itoa(move->move);
	ft_put_image('1', move, 0, 1);
	ft_put_image('1', move, 0, 0);
	mlx_string_put(move->mlx, move->win, 10, 20, 0x00008B, "Movimientos:  ");
	mlx_string_put(move->mlx, move->win, 135, 20, 0x00008B, count);
	ft_putstr_fd("Steps:  ", 1);
	ft_putendl_fd(count, 1);
	free(count);
}

int	ft_close(t_windows *init, char msg)
{
	mlx_destroy_window(init->mlx, init->win);
	if (msg == 'C')
		ft_putendl_fd("Has cerrado la ventana", 1);
	else if (msg == 'W')
		ft_putendl_fd("Has ganado!", 1);
	else if (msg == 'D')
		ft_putendl_fd("Has sido eliminado", 1);
	exit(EXIT_SUCCESS);
}

int	ft_close_x(t_windows *init)
{
	mlx_destroy_window(init->mlx, init->win);
	ft_putendl_fd("Has cerrado la ventana", 1);
	exit(EXIT_SUCCESS);
}

char	*ft_check_image(char *path)
{
	if (open((path), O_RDONLY) < 0)
		ft_error("Error, no hay imagen en directorio");
	return (path);
}

void	ft_init_struct(t_windows *init)
{
	init->map_len = 0;
	init->map_width = 0;
	init->exit = 0;
	init->collect = 0;
	init->pos = 0;
	init->img_h = 32;
	init->img_w = 32;
	init->steps = 0;
	init->frame = 0;
	init->time = 0;
	init->img_character = ft_check_image("images/img_character");
	init->img_0 = ft_check_image("images/img_0");
	init->img_1 = ft_check_image("images/img_1");
	init->img_C = ft_check_image("images/img_C");
	init->img_E = ft_check_image("images/img_E");
}