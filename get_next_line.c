/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:07:09 by jusato            #+#    #+#             */
/*   Updated: 2022/05/18 14:07:09 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *stat_str);
char	*make_return_line(char *read_line, char *ret_line);
char	*clear_and_save_next(char *read_line);

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!read_line)
		read_line = ft_calloc(1, sizeof(char));
	read_line = read_and_save(fd, read_line);
	if (!read_line)
		return (NULL);
	ret_line = NULL;
	ret_line = make_return_line(read_line, ret_line);
	read_line = clear_and_save_next(read_line); 
	return (ret_line);
}

char	*clear_and_save_next(char *read_line)
{
	char	*aux;
	size_t	i;
	size_t	size;

	i = 0;
	while (read_line[i] != '\n' && read_line[i])
		i ++;
	size = ft_strlen(read_line) - i;
	if (size > 0)
	{
		aux = malloc(size * sizeof(char));
		ft_strlcpy(aux, &read_line[i + 1], size);
		free(read_line);
		return(aux);
	}
	return (NULL);
}

char	*make_return_line(char *read_line, char *ret_line)
{
	size_t	i;

	i = 0;
	while (read_line[i] != '\n' && read_line[i])
		i ++;
	if (i <= ft_strlen(read_line))
	{
		ret_line = malloc(sizeof(char) * (i + 2));
		ft_strlcpy(ret_line, read_line, i + 2);
		return (ret_line);
	}
	return (NULL);
}

//AQUI ESTÁ O PROBLEMA, O WHILE PRECISA ESTAR AQUI MAS NÃO ESTÁ FUNCIONANDO
char	*read_and_save(int fd, char *stat_str)
{
	ssize_t	read_bytes;
	char	*buff;
	char	*aux;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_bytes = 1;
	aux = NULL;
	while (ft_strchr(stat_str, '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buff);
			return (aux);
		}
		aux = malloc((ft_strlen(stat_str) + BUFFER_SIZE + 1 ) * sizeof(char));
		aux = ft_strjoin(stat_str, buff);
		stat_str = aux;
		free(aux);
	}
	free(buff);
	return (stat_str);
}
