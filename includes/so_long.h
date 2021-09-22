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

/*STRUCTS*/

typedef struct s_object
{

}   t_object;

typedef struct s_windows
{
    char **map;

}   t_windows;

typedef struct s_image
{
    
}   t_image;

/*FUNCTIONS*/

/*Main*/

void    ft_check_args(int argc, char **argv);
int main(int argc, char **argv);

/*Init*/

void    ft_map_fill(t_windows *fill);

/*Utils*/

void	ft_error(char *str);

#endif

