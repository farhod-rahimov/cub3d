/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_if_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2021/02/05 10:10:37 by btammara         ###   ########.fr       */
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
	check_map_left_to_right(cub_file, 0, 0, 0);
	check_map_up_to_down(cub_file, 0, 0, 0);
	return (0);
}

void			check_map_left_to_right(t_parse **cub_file, int x, int y, int flag)
{
	char **tmp = (*cub_file)->map2d;
	while (tmp[y][x]) // слева направо
	{
		while (tmp[y][x])
		{
			if (x == 0)
			{
				if (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N'
				|| tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
					ft_error("map error. MAP should start with 1 or space. 0 should be surrounded by 1");
			}
			if (x > 1)
			{
				if ((tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N'
				|| tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E') && tmp[y][x - 1] == ' ')
					ft_error("map error. MAP should start with 1 or space. 0 should be surrounded by 1");
			}
			while (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			{
				flag = 1;
				x += (*cub_file)->scale;
			}
			if (tmp[y][x] != '1' && flag)
			{
				ft_error("map error. 0, 2, N, S, W or E should always be surrounded by 1. Example: 100020001");
			}
			flag = 0;
			x += (*cub_file)->scale;
		}
		x = 0;
		y += (*cub_file)->scale;
	}
}

void			check_map_up_to_down(t_parse **cub_file, int x, int y, int flag)
{
	char **tmp = (*cub_file)->map2d;
	while (tmp[y][x]) // сверху вниз
	{
		while (tmp[y][x])
		{
			if (y == 0)
			{
				if (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N'
				|| tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
					ft_error("map error. MAP should start with 1 or space. 0 should be surrounded by 1");
			}
			if (y > 1)
			{
				if ((tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N'
				|| tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E') && tmp[y - 1][x] == ' ')
					ft_error("map error. MAP should start with 1 or space. 0 should be surrounded by 1");
			}
			while (tmp[y][x] == '0' || tmp[y][x] == '2' || tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			{
				flag = 1;
				y += (*cub_file)->scale;
			}
			if (tmp[y][x] != '1' && flag)
			{
				ft_error("2map error. 0, 2, N, S, W or E should always be surrounded by 1. Example: 100020001");
			}
			flag = 0;
			y += (*cub_file)->scale;
		}
		y = 0;
		x += (*cub_file)->scale;
	}
}