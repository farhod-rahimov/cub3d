/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 08:44:20 by btammara          #+#    #+#             */
/*   Updated: 2020/12/13 17:56:02 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*checker_minus_1(int fd, char **remainder, char **line, int flag)
{
	char	*buf;
	int		a;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	else if (((a = read(fd, NULL, 0)) == -1))
		return (NULL);
	else if (BUFFER_SIZE < 1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (flag == -2)
	{
		if (!(*remainder = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (NULL);
		*remainder[0] = '\0';
	}
	if (line[0])
	{
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		*line[0] = '\0';
	}
	return (buf);
}

int		checker_remainder(char *remainder, char **line, int flag)
{
	char	*tmp;
	char	*p_n;

	if (remainder)
	{
		if ((p_n = ft_strchr(remainder, '\n')))
		{
			tmp = &(**line);
			*p_n = '\0';
			if ((*line = ft_strdup(remainder)) == NULL)
				return (-1);
			ft_strcpy(remainder, ++p_n);
			flag = -3;
		}
		else
		{
			tmp = &(**line);
			if ((*line = ft_strdup(remainder)) == NULL)
				return (-1);
			free(remainder);
			flag = -2;
		}
		free(tmp);
	}
	return (flag);
}

int		read_func(char *buf, char **line, char **remainder, int fd)
{
	char	*p_n;
	char	*tmp;
	int		byte_was_read;
	int		flag;

	flag = checker_remainder(*remainder, line, -2);
	while ((flag == -2) && ((byte_was_read = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			flag = -3;
			*p_n = '\0';
			if ((*remainder = ft_strdup(++p_n)) == NULL)
				return (-1);
		}
		tmp = &(**line);
		if ((*line = ft_strjoin(*line, buf)) == NULL)
			return (-1);
		free(tmp);
	}
	if (buf != NULL)
		free(buf);
	return ((byte_was_read == -1 || byte_was_read == 0) ? byte_was_read : flag);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static	char	*remainder;
	static	int		flag;

	if (flag != -3)
		flag = -2;
	if ((buf = checker_minus_1(fd, &remainder, line, flag)) == NULL)
		return (-1);
	flag = read_func(buf, line, &remainder, fd);
	if ((flag == -1 || flag == 0))
		return (flag);
	return (1);
}
