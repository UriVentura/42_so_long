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

#include "../includes/so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_printer(t_windows *move)
{
	char	*count;

	count = ft_itoa(move->move);
	put_image('1', move, 0, 1);
	put_image('1', move, 0, 0);
	mlx_string_put(move->mlx, move->win, 10, 20, 0xadff2f, "Movimientos:  ");
	mlx_string_put(move->mlx, move->win, 80, 20, 0x9acd32, count);
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
	t_image *img;

	init->map_len = 0;
	init->map_width = 0;
	init->exit = 0;
	img->collect = 0;
	img->pos = 0;
	img->img_h = 64;
	img->img_w = 64;
	img->steps = 0;
	init->frame = 0;
	init->time = 0;
	img->img_character = check_image("./images/img_character.xpm");
	img->img_0 = check_image("./images/img_0.xpm");
	img->img_1 = check_image("./images/img_1.xpm");
	img->img_C = check_image("./images/img_C.xpm");
	img->img_E = check_image("./images/img_E.xpm");
}