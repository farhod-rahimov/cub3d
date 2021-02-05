/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 08:55:01 by btammara          #+#    #+#             */
/*   Updated: 2021/02/05 09:03:59 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
