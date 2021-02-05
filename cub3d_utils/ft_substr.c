/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:44:06 by btammara          #+#    #+#             */
/*   Updated: 2020/12/14 10:10:45 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned	int	i;
	char			*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		if ((p = (char *)malloc(1 * sizeof(char))))
			p[0] = '\0';
		return (p);
	}
	if ((p = (char *)malloc((len + 1) * sizeof(char))))
	{
		while (i < len && s[start] != '\0')
			p[i++] = s[start++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
