/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:34:51 by oventura          #+#    #+#             */
/*   Updated: 2021/05/27 20:59:03 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The calloc() function contiguously allocates enough space for count
	objects that are size bytes of memory each and returns a pointer to the
	allocated memory.  The allocated memory is filled with bytes of value
	zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	x = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (x < count * size)
	{
		ptr[x] = 0;
		x++;
	}
	return ((void *)ptr);
}
