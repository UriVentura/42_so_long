/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oventura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:43:02 by oventura          #+#    #+#             */
/*   Updated: 2021/07/15 17:43:06 by oventura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif
int		get_next_line(int fd, char **line);
char	*gnl_read_line(int fd, char *read_line);
char	*gnl_write_line(ssize_t len_read, char *read_line, char **line_out);
char	*gnl_strjoin_n_free(char *s1, char *s2);
char	*gnl_strdup(char *src);
char	*gnl_strchr(char *s, int c);
size_t	gnl_strlen(char *str);

#endif