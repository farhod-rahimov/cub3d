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

#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
#include "./cub3d.h"
// gcc test.c libmlx.dylib -framework OpenGl -framework Appkit

int		check_sides_sprites_for_raycasting(t_parse *cub_file)
{
	cub_file->sprite_start = 0;
	int i = 0;
	int tmp_x = 0;
	// int tmp_x = cub_file->FOV * cub_file->Rx;
	cub_file->FOV = cub_file->player_a - (PI / 6);

	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	{
		if (cub_file->FOV >= 0)
		{
			if ((int)(cub_file->FOV * 180 / PI) % 360 >= 0 && (int)(cub_file->FOV * 180 / PI) % 360 < 90) // lower right
			{
				if (check_lower_side_sprites(cub_file, 0) <= check_right_side_sprites(cub_file, 0))
					check_lower_side_sprites(cub_file, 0);
				else
					check_right_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 90 && (int)(cub_file->FOV * 180 / PI) % 360 < 180) // lower left
			{
				if (check_lower_side_sprites(cub_file, 0) <= check_left_side_sprites(cub_file, 0) * -1)
					check_lower_side_sprites(cub_file, 0);
				else
					check_left_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 180 && (int)(cub_file->FOV * 180 / PI) % 360 < 270) // upper left
			{
				if (check_upper_side_sprites(cub_file, 0) * -1 <= check_left_side_sprites(cub_file, 0) * -1) // было < 
					check_upper_side_sprites(cub_file, 0);
				else
					check_left_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 270 && (int)(cub_file->FOV * 180 / PI) % 360 < 360) // upper right
			{
				if (check_upper_side_sprites(cub_file, 0) * -1 <= check_right_side_sprites(cub_file, 0))
					check_upper_side_sprites(cub_file, 0);
				else
					check_right_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
		}
		else
		{
			if ((int)(cub_file->FOV * 180 / PI) % 360 <= 0 && (int)(cub_file->FOV * 180 / PI) % 360 > -90) // upper right
			{
				if (check_upper_side_sprites(cub_file, 0) * -1 <= check_right_side_sprites(cub_file, 0))
					check_upper_side_sprites(cub_file, 0);
				else
					check_right_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -90 && (int)(cub_file->FOV * 180 / PI) % 360 > -180) // upper left
			{
				if (check_upper_side_sprites(cub_file, 0) * -1 <= check_left_side_sprites(cub_file, 0) * -1) // было < 
					check_upper_side_sprites(cub_file, 0);
				else
					check_left_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -180 && (int)(cub_file->FOV * 180 / PI) % 360 > -270) // lower left
			{
				if (check_lower_side_sprites(cub_file, 0) <= check_left_side_sprites(cub_file, 0) * -1)
					check_lower_side_sprites(cub_file, 0);
				else
					check_left_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -270 && (int)(cub_file->FOV * 180 / PI) % 360 > -360) // lower right
			{
				if (check_lower_side_sprites(cub_file, 0) <= check_right_side_sprites(cub_file, 0))
					check_lower_side_sprites(cub_file, 0);
				else
					check_right_side_sprites(cub_file, 0);
				if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i == 0)
				{
					cub_file->sprite_start = tmp_x;
					cub_file->sprite_len_of_c = cub_file->len_of_c;
					i++;
				}
				else if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '1' && i != 0)
				{
					cub_file->sprite_end = tmp_x;
					return (cub_file->sprite_start);
				}
			}
		}
		cub_file->FOV += (PI / 3) / cub_file->Rx;
		tmp_x++;
		// tmp_x = cub_file->FOV * cub_file->Rx;
	}
	// printf("ret\n");
	if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2' && i != 0)
	{
		cub_file->sprite_end = tmp_x;
		return (cub_file->sprite_start);
	}
	return (-1); // there is no sprite
}