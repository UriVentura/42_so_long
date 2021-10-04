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

#include "includes/so_long.h"

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

void	ft_map_count(char *map, t_windows *win)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error, no hay ningún archivo\n");
	count = 1;
	while (count == 1)
	{
		count = get_next_line(fd, &line);
		free(line);
		win->map_width += 1;
	}
	if (count == -1)
		ft_error("Error, GNL no valido\n");
	close(fd);
}

void	ft_walls_tb(t_windows *wall)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(wall->map[wall->map_width - 1]) != wall->map_len)
		ft_error("Error, el mapa está mal\n");
	while (wall->map[0][i])
	{
		if (wall->map[0][i] != '1')
			ft_error("Error, el 'top' está mal\n");
		i++;
	}
	i = 0;
	while (wall->map[wall->map_width - 1][i])
	{
		if (wall->map[wall->map_width - 1][i] != '1')
			ft_error("Error, el 'bot' está mal\n");
		i++;
	}
}

void	ft_body_map(char *map_line, t_windows *check)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(map_line) != check->map_len)
		ft_error("Error, el mapa está mal\n");
	if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
		ft_error("Error, el mapa está mal\n");
	while (map_line[i])
	{
		if (map_line[i] == 'E')
			check->exit += 1;
		else if (map_line[i] == 'C')
			check->collect += 1;
		else if (map_line[i] == 'P')
			check->pos += 1;
		else if (map_line[i] == '1' || map_line[i] == '0')
			;
		else
			ft_error("Error, el mapa no tiene los simbolos correspondientes\n");
		i++;
	}
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
