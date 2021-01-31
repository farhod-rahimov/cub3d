/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:03:41 by btammara          #+#    #+#             */
/*   Updated: 2020/12/15 15:58:556 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	check_sides_sprites_for_raycasting(t_parse **cub_file, int i) // ok
{
	if ((*cub_file)->FOV >= 0)
	{
		if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 0 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 90) // lower right
		{
			check_lower_side_sprites(cub_file, i);
			check_right_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 90 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 180) // lower left
		{
			check_lower_side_sprites(cub_file, i);
			check_left_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 180 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 270) // upper left
		{
			check_upper_side_sprites(cub_file, i);
			check_left_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 270 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 360) // upper right
		{
			check_upper_side_sprites(cub_file, i);
			check_right_side_sprites(cub_file, i);
		}
	}
	else
	{
		if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= 0 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -90) // upper right
		{
			check_upper_side_sprites(cub_file, i);
			check_right_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -90 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -180) // upper left
		{
			check_upper_side_sprites(cub_file, i);
			check_left_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -180 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -270) // lower left
		{
			check_lower_side_sprites(cub_file, i);
			check_left_side_sprites(cub_file, i);
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -270 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -360) // lower right
		{
			check_lower_side_sprites(cub_file, i);
			check_right_side_sprites(cub_file, i);
		}
	}
}