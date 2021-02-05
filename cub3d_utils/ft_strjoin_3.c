/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 08:44:33 by btammara          #+#    #+#             */
/*   Updated: 2021/02/03 17:10:49 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s1 == NULL)
		len = ft_strlen(s2) + ft_strlen(s3);
	else
		len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
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
		p[len++] = s3[0];
		p[len] = '\0';
		return (p);
	}
	return (NULL);
}