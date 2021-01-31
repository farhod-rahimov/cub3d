/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/31 19:47:15 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
#include "../cub3d.h"

long double check_upper_side_walls(t_parse **cub_file, int i)
{
	(*cub_file)->len_of_c = 0;
	while (1) // UPPER
	{
		(*cub_file)->len_of_c = ((SCALE * i++ + (((*cub_file)->player_y % SCALE) + 1)) / sinl((*cub_file)->FOV));
		(*cub_file)->c_x = (*cub_file)->player_x - (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y - (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;

		if ((*cub_file)->c_x > (*cub_file)->map_x * SCALE || (*cub_file)->c_y > (*cub_file)->map_y * SCALE ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
		{
			(*cub_file)->len_of_c = (*cub_file)->Rx * -10;
			break ;
		}
		if (((*cub_file)->map2d[(int)(*cub_file)->c_y + SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x + SCALE / 20] == '1')
		|| ((*cub_file)->map2d[(int)(*cub_file)->c_y + SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x - SCALE / 20] == '1'))
		{
			break ;
		}
		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '0' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '2')
		{
			break ;
		}
	}
	return ((*cub_file)->len_of_c);
}

long double check_lower_side_walls(t_parse **cub_file, int i)
{
	(*cub_file)->len_of_c = 0;
	while (1) // LOWER
	{
		(*cub_file)->len_of_c = (SCALE * i++ + (SCALE - ((*cub_file)->player_y % SCALE))) / sinl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x + (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y + (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;

		if ((*cub_file)->c_x > (*cub_file)->map_x * SCALE || (*cub_file)->c_y > (*cub_file)->map_y * SCALE ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
		{
			(*cub_file)->len_of_c = (*cub_file)->Rx * 10;
			break ;
		}
		if (((*cub_file)->map2d[(int)(*cub_file)->c_y - SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x + SCALE / 20] == '1')
		|| ((*cub_file)->map2d[(int)(*cub_file)->c_y - SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x - SCALE / 20] == '1'))
		{
			break ;
		}
		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '0' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '2')
		{
			break ;
		}
	}
	return ((*cub_file)->len_of_c);
}

long double check_left_side_walls(t_parse **cub_file, int i)
{
	(*cub_file)->len_of_c = 0;
	while (1) // LEFT
	{
		(*cub_file)->len_of_c = (SCALE * i++ + (((*cub_file)->player_x % SCALE) + 1)) / cosl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x - (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y - (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;
	
		if ((*cub_file)->c_x > (*cub_file)->map_x * SCALE || (*cub_file)->c_y > (*cub_file)->map_y * SCALE ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
		{
			(*cub_file)->len_of_c = (*cub_file)->Rx * -10;
			break ;
		}
		if (((int)((*cub_file)->FOV * 180 / PI) % 360 >= 180 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 360)
		|| ((int)((*cub_file)->FOV * 180 / PI) % 360 >= -180 && (int)((*cub_file)->FOV * 180 / PI) % 360 <= 0))
		{
			if ((*cub_file)->map2d[(int)(*cub_file)->c_y + SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x + SCALE / 20] == '1')
				break ;
		}
		else
		{
			if ((*cub_file)->map2d[(int)(*cub_file)->c_y - SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x + SCALE / 20] == '1')
				break ;
		}
		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '0' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '2')
		{
			break ;
		}
	}
	return ((*cub_file)->len_of_c);
}

long double check_right_side_walls(t_parse **cub_file, int i)
{
	(*cub_file)->len_of_c = 0;
	while (1) // RIGHT
	{
		(*cub_file)->len_of_c = (SCALE * i++ + (SCALE - ((*cub_file)->player_x % SCALE))) / cosl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x + (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y + (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;
;
		if ((*cub_file)->c_x > (*cub_file)->map_x * SCALE || (*cub_file)->c_y > (*cub_file)->map_y * SCALE ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
		{
			(*cub_file)->len_of_c = (*cub_file)->Rx * 10;
			break ;
		}
		if (((int)((*cub_file)->FOV * 180 / PI) % 360 >= 180 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 360)
		|| ((int)((*cub_file)->FOV * 180 / PI) % 360 >= -180 && (int)((*cub_file)->FOV * 180 / PI) % 360 <= 0))
		{
			if ((*cub_file)->map2d[(int)(*cub_file)->c_y + SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x - SCALE / 20] == '1')
				break ;
		}
		else
		{
			if ((*cub_file)->map2d[(int)(*cub_file)->c_y - SCALE / 20][(int)(*cub_file)->c_x] == '1' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x - SCALE / 20] == '1')
				break ;
		}
		
		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '0' && (*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] != '2')
		{
			break ;
		}
	}
	return ((*cub_file)->len_of_c);
}