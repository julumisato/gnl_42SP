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
	while (*str)
	{
		count ++;
		str ++;
	}
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

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (*s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i ++;
		}
	}
	j = 0;
	while (i < len && s2[j])
		str[i++] = s2[j++];
	str[len] = '\0';
	return (str);
}


char	*ft_strchr(const char *str, int c)
{
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
