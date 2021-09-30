/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <oventura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:02 by oventura          #+#    #+#             */
/*   Updated: 2021/05/27 21:05:50 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The strdup() function allocates sufficient memory for a copy of the
	string s1, does the copy, and returns a pointer to it.  The pointer may
	subsequently be used as an argument to the function free(3).

	If insufficient memory is available, NULL is returned and errno is set to
	ENOMEM.

	The strndup() function copies at most n characters from the string s1
	always NUL terminating the copied string.
*/

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;
	size_t	x;

	x = 0;
	l = ft_strlen(s1);
	str = (void *)malloc(sizeof(*str) * (l + 1));
	if (!str)
		return (NULL);
	while (x < l)
	{
		*(str + x) = *(s1 + x);
		x++;
	}
	str[x] = '\0';
	return (str);
}
