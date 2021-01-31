/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_if_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2021/01/31 15:46:28 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_if_map_is_last(t_parse **cub_file)  // ok
{
	if ((*cub_file)->Rx == -1 || (*cub_file)->Ry == -1)
		ft_error("*.cub file is wrong. There is no RESOLUTION");
	if ((*cub_file)->NO == NULL)
		ft_error("*.cub file is wrong. There is no path to NORTH TEXTURE");
	if ((*cub_file)->SO == NULL)
		ft_error("*.cub file is wrong. There is no path to SOUTH TEXTURE");
	if ((*cub_file)->WE == NULL)
		ft_error("*.cub file is wrong. There is no path to WEST TEXTURE");
	if ((*cub_file)->EA == NULL)
		ft_error("*.cub file is wrong. There is no path to EAST TEXTURE");
	if ((*cub_file)->S == NULL)
		ft_error("*.cub file is wrong. There is no path to SPRITE TEXTURE");
	if ((*cub_file)->floor[0] == -1 || (*cub_file)->floor[1] == -1 || (*cub_file)->floor[2] == -1)
		ft_error("*.cub file is wrong. There is no floor color");
	if ((*cub_file)->ceilling[0] == -1 || (*cub_file)->ceilling[1] == -1 || (*cub_file)->ceilling[2] == -1)
		ft_error("*.cub file is wrong. There is no ceilling color");
	if ((*cub_file)->map_y < 3)
		ft_error("invalid map. Either there is no MAP or it is not surrounded by walls");
	return (0);
}

int					check_if_map_is_ok(t_parse **cub_file)
{
	check_map_left_to_right((*cub_file)->map2d, 0, 0, 0);
	check_map_up_to_down((*cub_file)->map2d, 0, 0, 0);
	return (0);
}

void			check_map_left_to_right(char **tmp, int x, int y, int flag)
{
	while (tmp[y][x]) // слева направо
	{
		while (tmp[y][x])
		{
			while (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			{
				flag = 1;
				x += SCALE;
			}
			if (x - SCALE == 0)
			{
				if (tmp[y][x - SCALE] == '0' || tmp[y][x - SCALE] == '2' || tmp[y][x - SCALE] == 'N'
				|| tmp[y][x - SCALE] == 'S' || tmp[y][x - SCALE] == 'W' || tmp[y][x - SCALE] == 'E')
					ft_error("map error. MAP should start with 1 or space.");
			}
			if (x > SCALE * 2)
			{
				if (tmp[y][x - SCALE] == '0' && tmp[y][x - SCALE * 2] == ' ')
				{
					printf("y %d, x %d\n", y / SCALE, x / SCALE);
					printf("x - SCALE %c, x - SCALE * 2 %c", tmp[y][x - SCALE], tmp[y][x - 2 * SCALE]);
					ft_error("map error. 0, 2, N, S, W or E cannot be BETWEEN SPACES and should always be surrounded by 1. Example: 100020001");
				}
			}
			if (tmp[y][x] != '1' && flag)
			{
				printf("y %d, x %d\n", y / SCALE, x / SCALE);
				ft_error("map error. 0, 2, N, S, W or E should always be surrounded by 1. Example: 100020001");
			}
			flag = 0;
			x += SCALE;
		}
		x = 0;
		y += SCALE;
	}
}

void			check_map_up_to_down(char **tmp, int x, int y, int flag)
{
	while (tmp[y][x]) // сверху вниз
	{
		while (tmp[y][x])
		{
			while (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			{
				flag = 1;
				y += SCALE;
			}
			if (y - SCALE == 0)
			{
				if (tmp[y - SCALE][x] == '0' || tmp[y - SCALE][x] == '2' || tmp[y - SCALE][x] == 'N'
				|| tmp[y - SCALE][x] == 'S' || tmp[y - SCALE][x] == 'W' || tmp[y - SCALE][x] == 'E')
					ft_error("2map error. MAP should start with 1 or space.");
			}
			if (y > SCALE * 2)
			{
				if (tmp[y - SCALE][x] == '0' && tmp[y - SCALE * 2][x] == ' ')
				{
					printf("y %d, x %d\n", y / SCALE, x / SCALE);
					printf("x - SCALE %c, x - SCALE * 2 %c", tmp[y - SCALE][x], tmp[y - 2 * SCALE][x]);
					ft_error("2map error. 0, 2, N, S, W or E cannot be BETWEEN SPACES and should always be surrounded by 1. Example: 100020001");
				}
			}
			if (tmp[y][x] != '1' && flag)
			{
				printf("y %d, x %d\n", y / SCALE, x / SCALE);
				ft_error("2map error. 0, 2, N, S, W or E should always be surrounded by 1. Example: 100020001");
			}
			flag = 0;
			y += SCALE;
		}
		y = 0;
		x += SCALE;
	}
}