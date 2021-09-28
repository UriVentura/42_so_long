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