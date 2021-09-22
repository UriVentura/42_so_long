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

#include "../includes/so_long.h"

void    ft_map_fill(t_windows *fill)
{
    int w;
    int len;

    w = 0;
    while (fill->map[w][len])
    {
        len = 0;
        while (fill->map[w][len])
        {
            ft_put_image(fill->map[w][len], fill, w, len);
            len++;
        }
        w++;
    }
}

void    ft_init(t_windows *init)
{
    init->mlx = mlx_init();
    init->win = mlx_new_window(init->mlx, init->map_len * 64, 
                                init->map_width *64, "so long");
    ft_map_fill(init);
    //movimiento 
    //cierre
    //animación
    mlx_loop(init->mlx);
}

void ft_init_so_long(char *map)
{
    t_windows init;
}