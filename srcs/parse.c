/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:14:38 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 11:14:38 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_map_parse(char *map, t_windows *win)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error, no hay ningún archivo\n");
	win->map = ft_calloc(win->map_width + 1, sizeof(char *));
	count = 1;
	while (count == 1)
	{
		count = get_next_line(fd, &line);
		win->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	if (count == -1)
		ft_error("Error, GNL no valido\n");
	close(fd);
}