/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/08 08:44:13 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_upper_side(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1)
	{
		cub_file->len_of_c = (SCALE * i++ + (cub_file->player_y % SCALE)) / sinf(cub_file->FOV);
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV) + 2;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinf(cub_file->FOV) - 1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = -2000;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '8'
		&& cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '9')
		{
			while (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] == '0')
			{
				cub_file->len_of_c -= 0.01;
				if ((cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV)) < 0)
					break ;
				if ((cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinf(cub_file->FOV)) < 0)
					break ;
			}
			while (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0'  && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '8'
			&& cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '9')
			{
				cub_file->len_of_c += 0.01;
				if ((cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV)) < 0)
					break ;
				if ((cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinf(cub_file->FOV)) < 0)
					break ;
			} 
			printf("UP\n");
			break ;
		}
	}
	return (cub_file->len_of_c);
}

int check_lower_side(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1)
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_y % SCALE))) / sinf(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV);
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinf(cub_file->FOV);
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = 2000;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '8'
		&& cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '9')
		{
			while (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '8'
			&& cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '9')
			{
				cub_file->len_of_c = cub_file->len_of_c - 0.01;
				if ((cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV)) < 0)
					break ;
				if ((cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinf(cub_file->FOV)) < 0)
					break ;
			}
			break ;
		}
		printf("DOWN\n");
	}
	return (cub_file->len_of_c);
}

int check_left_side(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1)
	{
		cub_file->len_of_c = (SCALE * i++ + (cub_file->player_x % SCALE)) / cosf(cub_file->FOV);
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV);
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinf(cub_file->FOV);
		if (((int)(cub_file->FOV * 180 / PI) % 360 == 270 || (int)(cub_file->FOV * 180 / PI) % 360 == -90)
		|| (((int)(cub_file->FOV * 180 / PI) % 360 == 90 || (int)(cub_file->FOV * 180 / PI) % 360 == -270)))
			cub_file->len_of_c = -10000;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = -2000;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '1')
		{
			while (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '1')
			{
				cub_file->len_of_c = cub_file->len_of_c + 0.01;
				if ((cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV)) < 0)
					break ;
				if ((cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinf(cub_file->FOV)) < 0)
					break ;
			}
			printf("LEFT\n");
			break ;
		}
	}
	return (cub_file->len_of_c);
}

int check_right_side(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1)
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_x % SCALE))) / cosf(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV);
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinf(cub_file->FOV);
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = 2000;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '1')
		{
			cub_file->len_of_c = (SCALE * --i + (SCALE - (cub_file->player_x % SCALE))) / cosf(cub_file->FOV);
			while (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '1')
			{
				cub_file->len_of_c = cub_file->len_of_c - 0.01;
				if ((cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV)) < 0)
					break ;
				if ((cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinf(cub_file->FOV)) < 0)
					break ;
			}
			// if ((int)(cub_file->FOV * 180 / PI) % 360 == 0)
			// 	cub_file->len_of_c--;
			printf("RIGHT\n");
			break ;
		}
	}
	return (cub_file->len_of_c);
}