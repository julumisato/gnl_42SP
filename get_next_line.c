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

char	*read_from_fd_and_save(int fd, char *read_line);
char	*make_return_line(char *read_line, char *ret_line);

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*ret_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_line = read_from_fd_and_save(fd, read_line);
	if (!read_line)
		return (NULL);
	ret_line = NULL;
	ret_line = make_return_line(read_line, ret_line);
//	read_line = clear_and_save_remaining(read_line);
	return (ret_line);
}

char	*read_from_fd_and_save(int fd, char *read_line)
{
	char	*buff;
	ssize_t	read_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (ft_strchr(buff, '\n') == NULL)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		read_line = ft_strjoin(read_line, buff);
	}
	free(buff);
	return (read_line);
}

char	*make_return_line(char *read_line, char *ret_line)
{
	size_t i;

	i = 0;
	while (read_line[i] != '\n')
		i ++;
	ret_line = malloc(i + 2);
	if (!ret_line)
		return (NULL);
	ft_strlcpy(ret_line, read_line, i + 2);
	return (ret_line);
}
