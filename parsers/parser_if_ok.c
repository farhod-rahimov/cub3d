/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_if_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2020/12/29 17:29:31 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../get_next_line/get_next_line.h"

int	check_if_map_is_last(t_parse **cub_file)
{
	if ((*cub_file)->Rx == -1 || (*cub_file)->Ry == -1)
		return (-1);
	if ((*cub_file)->NO == NULL || (*cub_file)->SO == NULL)
		return (-1);
	if ((*cub_file)->WE == NULL || (*cub_file)->EA == NULL)
		return (-1);
	if ((*cub_file)->S == NULL)
		return (-1);
	if ((*cub_file)->Fr == -1 || (*cub_file)->Fg == -1 || (*cub_file)->Fb == -1)
		return (-1);
	if ((*cub_file)->Cr == -1 || (*cub_file)->Cg == -1 || (*cub_file)->Cb == -1)
	{
		printf("there is no ceiling texture path in the config file .cub\n");
		return (-1);
	}
	if ((*cub_file)->map_y < 3)
	{
		printf("invalid map\n");
		return (-1); // invalid map
	}
	return (0);
}

int					check_if_parsed_file_is_ok(t_parse **cub_file)
{
	check_if_resolution_is_ok(cub_file);
	if (check_if_floor_color_is_ok(cub_file) == -1)
		return (-1);
	if (check_if_ceiling_color_is_ok(cub_file) == -1)
		return (-1);
	// if (check_if_map_is_ok(cub_file) == -1)
	// 	return (-1);
	return (0);
}

void				check_if_resolution_is_ok(t_parse **cub_file)
{
	if ((*cub_file)->Rx > 3200 || (*cub_file)->Rx < 0)
		(*cub_file)->Rx = 3200;
	if ((*cub_file)->Ry > 1800 || (*cub_file)->Ry < 0)
		(*cub_file)->Ry = 1800;
}

int					check_if_floor_color_is_ok(t_parse **cub_file)
{
	if ((*cub_file)->Fr > 240 || (*cub_file)->Fr < 0)
		return (-1);
	if ((*cub_file)->Fg > 240 || (*cub_file)->Fg < 0)
		return (-1);
	if ((*cub_file)->Fb > 240 || (*cub_file)->Fb < 0)
		return (-1);
	return (0);
}

int					check_if_ceiling_color_is_ok(t_parse **cub_file)
{
	if ((*cub_file)->Cr > 240 || (*cub_file)->Cr < 0)
		return (-1);
	if ((*cub_file)->Cg > 240 || (*cub_file)->Cg < 0)
		return (-1);
	if ((*cub_file)->Cb > 240 || (*cub_file)->Cb < 0)
		return (-1);
	return (0);
}

int					check_if_map_is_ok(t_parse **cub_file)
{
	char	**tmp;
	int		x;
	int		y;
	
	x = 0;
	tmp = (*cub_file)->map2d;
	if (tmp[0][x])
	{
		while((tmp[0][x] == ' ' || tmp[0][x] == '1'))
			x++;
		if (tmp[0][x] != '\0')
		{
			printf("map error (x00)\n");
			return (-1);
		}
	}
	y = 0;
	if (tmp[y][0])
	{
		while(tmp[y][0] == ' ' || tmp[y][0] == '1')
			y++;
		if (tmp[y][0] != '\0')
		{
			printf("map error (y00)\n");
			return (-1);
		}
	}
	x = 0;
	y = 0;
	while (tmp[y][x]) // проверка слева на право по строке
	{
		while (tmp[y][x] == ' ')
			x++;
		while(tmp[y][x])
		{
			if (x == 1)
			{
				if (tmp[y][x] == '0' && tmp[y][x - 1] != '1')
				{
					printf("map error (start wall (x) is '0')\n");
					return (-1);
				}
			}
			if (x > 1)
			{
				if (tmp[y][x - 2] == ' ')
					if (tmp[y][x] == '0' && tmp[y][x - 1] != '1')
					{
						printf("map error (start wall (x) is '0')\n");
						return (-1);
					}
			}
			if (tmp[y][x] == '0' && tmp[y][x + 1] == '\0')
			{
				printf("map error (end wall (x) is '0')\n");
				return (-1);
			}
			if (tmp[y][x] == ' ' && tmp[y][x + 1] != ' ' && tmp[y][x + 1] != '1'
			&& tmp[y][x + 1] != '\0')
			{
				printf("map error (there is space (x1))\n");
				return (-1);
			}
			x++;	
		}
		y++;
		x = 0;
	}
	x = 0;
	y = 0;
	while (tmp[y][x]) // проверка сверху вниз по столбцам
	{
		while (tmp[y][x] == ' ')
			y++;
		if (tmp[y][x] == '0')
		{
			if (tmp[y][x] == '0' && tmp[y - 1][x] != '1' && tmp[y - 1][x] != '0')
			{
				printf("map error (start wall (y) is ' ')\n");
				printf("y[%d]x[%d]\n", y, x);
				return (-1);
			}
		}
		while(tmp[y][x])
		{
			if (tmp[y][x] == '0' && tmp[y + 1][x] == '\0')
			{
				printf("map error (end wall (y) is '0')\n");
				return (-1);
			}
			if (tmp[y][x] == '0' && tmp[y + 1][x] == ' ')
			{
				printf("map error (end wall (y) iss ' ')\n");
				return (-1);
			}
			y++;	
		}
		x++;
		y = 0;
	}
	return (0);
}