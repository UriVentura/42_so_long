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
# include <time.h>
# include <fcntl.h>
# include "limits.h"

# include "../mlx/mlx.h"
# include "../libft/libft.h"

/*STRUCTS*/

typedef struct s_windows
{
    char    **map;
    int     map_len;
    int     map_width;
    int	    pos_x;
	int		pos_y;
    int     move;
    void    *mlx;
    void    *win;
    int     exit;
    int     time;
    int     frame;
	int     img_h;
    int     img_w;
    void    *img_1;
    void    *img_0;
    void    *img_C;
    void    *img_E;
    void    *img_character;
    void    *img;
    int     pos;
    int     collect;
    int     steps;

}   t_windows;

/*FUNCTIONS*/

/*Main*/

void    ft_check_args(int argc, char **argv);
int     main(int argc, char **argv);

/*Init*/

void    ft_map_fill(t_windows *fill);
void    ft_init_game(t_windows *init);
void    ft_init_so_long(char *map);

/*Parse*/

void	ft_map_parse(char *map, t_windows *win);
void	ft_map_count(char *map, t_windows *win);
void	ft_walls_tb(t_windows *wall);
void	ft_body_map(char *map_line, t_windows *check);

/*Utils*/

void	ft_error(char *str);
void	ft_printer(t_windows *move);
int	    ft_close(t_windows *init, char msg);
int	    ft_close_x(t_windows *init);
char	*ft_check_image(char *path);
void	ft_init_struct(t_windows *init);
void	ft_checker(t_windows *check);

/*Move*/

void	ft_action_move(t_windows *win, int x, int y);
void	ft_move(t_windows *win, int x, int y);
int	    ft_push(int key, t_windows *win);

/*Fill*/

void	ft_static_images(char key, t_windows *win);
void	ft_main_character(char key, t_windows *win);
void	ft_put_image(char key, t_windows *win, int y, int x);
int	    ft_animation(t_windows *win);
void	ft_exit(t_windows *win);

#endif

