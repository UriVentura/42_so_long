#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	size_t	len;
	char	*aux;

	if (!s)
		return (0);
	aux = (char *)s;
	len = gnl_strlen(s) + 1;
	while (len-- > 0)
	{
		if (*aux++ == (char)c)
			return (--aux);
	}
	return (NULL);
}

char	*gnl_strdup_n_free(char *src)
{
	char	*output_str;
	int		i;

	output_str = (char *) malloc(sizeof (*src) * (gnl_strlen(src) + 1));
	if (!output_str)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		output_str[i] = src[i];
		i++;
	}
	output_str[i] = '\0';
	free(src);
	return (output_str);
}

char	*gnl_strjoin_n_free(char *s1, char *s2)
{
	char	*str;
	char	*aux_str;
	char	*aux_s1;
	char	*aux_s2;

	if (!s1)
	{
		str = gnl_strdup_n_free(s2);
		return (str);
	}
	str = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!str)
		return (NULL);
	aux_s1 = s1;
	aux_s2 = s2;
	aux_str = str;
	while (*aux_s1)
		*aux_str++ = *aux_s1++;
	while (*aux_s2)
		*aux_str++ = *aux_s2++;
	*aux_str = '\0';
	free(s1);
	free(s2);
	return (str);
}
