/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:46:24 by oventura          #+#    #+#             */
/*   Updated: 2021/10/04 20:06:55 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const void *s1, const void *s2)
{
	char	*t1;
	char	*t2;
	int		i;

	t1 = (char *)s1;
	t2 = (char *)s2;
	i = 0;
	while (t1[i] || t2[i])
	{
		if (t1[i] != t2[i])
			return (0);
		i++;
	}
	return (1);
}
