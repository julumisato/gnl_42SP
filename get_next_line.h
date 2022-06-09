/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:26:50 by jusato            #+#    #+#             */
/*   Updated: 2022/06/09 17:42:19 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h> //ssize_t

#include <stdio.h> //TEST!!

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

/*______________utils________________*/
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *str, size_t n);

#endif
