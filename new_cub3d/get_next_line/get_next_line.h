/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:47:02 by btammara          #+#    #+#             */
/*   Updated: 2020/12/04 08:47:23 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strcpy(char *dst, const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

char	*checker_minus_1(int fd, char **remainder, char **line, int flag);
int		checker_remainder(char *remainder, char **line, int flag);
int		read_func(char *buf, char **line, char **remainder, int fd);
int		get_next_line(int fd, char **line);

#endif
