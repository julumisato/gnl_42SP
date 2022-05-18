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

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!read_line)
		read_line = ft_calloc(1, sizeof(char));
	while (ft_strchr(read_line, '\n') == NULL)
	{
		read_line = read_and_save(fd, read_line);
	}
	if (!read_line)
		return (NULL);
	ret_line = NULL;
	ret_line = make_return_line(read_line, ret_line);
//	read_line = clear_and_save_remaining(read_line); limpar e guardar os próximos;
	free(read_line); //tirar depois de fazer o clear_and_save_remaining
	return (ret_line);
}

char	*make_return_line(char *read_line, char *ret_line)
{
	size_t	i;

	i = 0;
	while (read_line[i] != '\n')
		i ++;
	
}

char	*read_and_save(int fd, char *stat_str)
{
	ssize_t	read_bytes;
	char	*buff;
	char	*aux;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(buff);
		return (NULL);
	}
	aux = malloc((ft_strlen(stat_str) + BUFFER_SIZE + 1 ) * sizeof(char));
	aux = ft_strjoin(stat_str, buff);
	free(buff);
	free(stat_str);
	return (aux);
}
