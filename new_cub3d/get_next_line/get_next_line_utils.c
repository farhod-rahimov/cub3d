/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:31:13 by btammara          #+#    #+#             */
/*   Updated: 2020/12/13 18:18:30 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == (char)c))
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char					*p;
	unsigned long long int	i;
	unsigned long long int	a;

	i = 0;
	a = 0;
	while (s1[i] != '\0')
		i++;
	if ((p = (char *)malloc((i + 1) * sizeof(char))))
	{
		while (a < i)
		{
			p[a] = s1[a];
			a++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

int		ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s1 == NULL)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if ((p = (char *)malloc((len + 1) * sizeof(char))))
	{
		if (s1 != NULL)
		{
			while (s1[i] != '\0')
			{
				p[i] = s1[i];
				i++;
			}
		}
		len = i;
		i = 0;
		while (s2[i] != '\0')
			p[len++] = s2[i++];
		p[len] = '\0';
		return (p);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	unsigned long int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
