/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_and_free_map2d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:56:07 by btammara          #+#    #+#             */
/*   Updated: 2021/01/17 15:17:56 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **ft_copy_map2d(char **map2d, t_parse *cub_file)
{
	char **new_map2d;
	int y = 0;

	if (!(new_map2d = (char **)malloc(sizeof(char *) * (((cub_file)->map_y * SCALE) + 1))))
		return (NULL);
	while (y <= (cub_file->map_y * SCALE))
	{
		if (!(new_map2d[y] = ft_strdup(map2d[y])))
			return (NULL);
		y++;
	}
	
	return (new_map2d);
}

void ft_free_map2d(char **map2d, t_parse *cub_file)
{
	int y = 0;

	while (y <= (cub_file->map_y * SCALE))
	{
		free(map2d[y]);
		y++;
	}
	free(map2d);
}