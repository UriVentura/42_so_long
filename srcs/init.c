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