/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:24:13 by jusato            #+#    #+#             */
/*   Updated: 2022/05/18 16:24:13 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count ++;
	return (count);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	ssize_t	len;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i ++;
	while(s2[j])
		j ++;
	len = i + j;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(&str[i], s2, j + 1);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str ++;
	}
	if ((char)c == '\0' && *str == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t		size;
	size_t		i;
	char		*dup;

	i = 0;
	while (s[i])
		i++;
	size = (i + 1);
	dup = (char *)malloc(size * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total;

	total = n * size;
	if (n != 0 && total / n != size)
		return (NULL);
	ptr = (char *)malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * n);
	return ((void *)ptr);
}

void	ft_bzero(void *str, size_t n)
{
	char	*newstr;

	newstr = (char *)str;
	while (n != 0)
	{
		newstr[n -1] = 0;
		n --;
	}
}
