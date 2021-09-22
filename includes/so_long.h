/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:47:32 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 09:47:32 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*INCLUDES*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include "limits.h"

# include "../mlx/mlx.h"

/*STRUCTS*/

typedef struct s_object
{
    void	*main_character;

}   t_object;

typedef struct s_windows
{
    char **map;
    int  map_len;
    int  map_width;
    void *mlx;
    void *win;

}   t_windows;

typedef struct s_image
{
    int img_h;
    int img_w;

}   t_image;

/*FUNCTIONS*/

/*Main*/

void    ft_check_args(int argc, char **argv);
int     main(int argc, char **argv);

/*Init*/

void    ft_map_fill(t_windows *fill);
void    ft_init(t_windows *init);
void    ft_init_so_long(char *map);

/*Parse*/

void	ft_map_parse(char *map, t_windows *win);
void	ft_map_count(char *map, t_windows *win);
void	ft_walls_tb(t_windows *wall);

/*Utils*/

void	ft_error(char *str);

#endif

