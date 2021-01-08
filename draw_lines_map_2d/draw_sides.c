/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/08 08:13:44 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_upper_side(t_parse *cub_file)
{
	// printf("upper %f\n", cub_file->FOV * 180 / PI);
	while ((cub_file->len_of_c) < 0)
	{
		if ((cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV)) <= 0)
			break ;
		if ((cub_file->c_y = cub_file->player_y - cub_file->len_of_c++ * sinf(cub_file->FOV)) <= 0)
			break ;
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	}
}

void draw_lower_side(t_parse *cub_file)
{
	while ((cub_file->len_of_c) > 0)
	{
		if ((cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV)) <= 0)
			break ;
		if ((cub_file->c_y = cub_file->player_y + cub_file->len_of_c-- * sinf(cub_file->FOV)) <= 0)
			break ;
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	}
}

void draw_left_side(t_parse *cub_file)
{
	while ((cub_file->len_of_c) < 0)
	{
		if ((cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosf(cub_file->FOV)) <= 0)
			break ;
		if ((cub_file->c_y = cub_file->player_y - cub_file->len_of_c++ * sinf(cub_file->FOV)) <= 0)
			break ;
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	}
}

void draw_right_side(t_parse *cub_file)
{
	while ((cub_file->len_of_c) > 0)
	{
		if ((cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV)) <= 0)
			break ;
		if ((cub_file->c_y = cub_file->player_y + cub_file->len_of_c-- * sinf(cub_file->FOV)) <= 0)
			break ;
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	}
}