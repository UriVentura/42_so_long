/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:44:02 by oventura          #+#    #+#             */
/*   Updated: 2021/09/22 09:44:02 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Error, no hay mapa\n");
	if (argc > 2)
		ft_error("Error, hay demasiados argumentos\n");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", \
				max_len(ft_strrchr(argv[1], '.'), ".ber")) != 0)
			ft_error("Error, la extensión es incorrecta");
	}
	else
		ft_error("Error, la extensión es incorrecta");
}

int	main(int argc, char **argv)
{
	ft_check_args(argc, argv);
	ft_init_so_long(argv[1]);
	return (0);
}
