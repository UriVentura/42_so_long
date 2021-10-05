/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:43:09 by oventura          #+#    #+#             */
/*   Updated: 2021/09/29 16:43:09 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_checker(t_windows *check)
{
	int	i;

	i = 1;
	check->map_len = (int)ft_strlen(check->map[0]);
	ft_walls_tb(check);
	while (i < check->map_width)
	{
		ft_body_map(check->map[i], check);
		i++;
	}
	if (check->exit != 1 || check->collect == 0 || check->pos != 1)
		ft_error("Error, no están todos los elementos\n");
	if (check->map_width > 17 || check->map_len > 39)
		ft_error("Error, no están todos los elementos\n");
}
