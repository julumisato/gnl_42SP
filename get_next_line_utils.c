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
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc (1 * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && *s1)
	{
		str[i] = *s1;
		s1 ++;
		i ++;
	}
	while (i < len && *s2)
	{
		str[i] = *s2;
		s2 ++;
		i ++;
	}
	str[i] = '\0';
	if (str == NULL)
		return (NULL);
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
