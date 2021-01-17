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

int		check_num_of_sprites(t_parse *cub_file)
{
	if (cub_file->FOV >= 0)
	{
		if ((int)(cub_file->FOV * 180 / PI) % 360 >= 0 && (int)(cub_file->FOV * 180 / PI) % 360 < 90) // lower right
		{
			if (check_lower_side_sprites(cub_file, 0) >= check_right_side_sprites(cub_file, 0))
				return (check_lower_side_sprites(cub_file, 0));
			else
				return (check_right_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 90 && (int)(cub_file->FOV * 180 / PI) % 360 < 180) // lower left
		{
			if (check_lower_side_sprites(cub_file, 0) >= check_left_side_sprites(cub_file, 0))
				return (check_lower_side_sprites(cub_file, 0));
			else
				return (check_left_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 180 && (int)(cub_file->FOV * 180 / PI) % 360 < 270) // upper left
		{
			if (check_upper_side_sprites(cub_file, 0) >= check_left_side_sprites(cub_file, 0)) // было < 
				return (check_upper_side_sprites(cub_file, 0));
			else
				return (check_left_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 270 && (int)(cub_file->FOV * 180 / PI) % 360 < 360) // upper right
		{
			if (check_upper_side_sprites(cub_file, 0) >= check_right_side_sprites(cub_file, 0))
				return (check_upper_side_sprites(cub_file, 0));
			else
				return (check_right_side_sprites(cub_file, 0));
		}
	}
	else
	{
		if ((int)(cub_file->FOV * 180 / PI) % 360 <= 0 && (int)(cub_file->FOV * 180 / PI) % 360 > -90) // upper right
		{
			if (check_upper_side_sprites(cub_file, 0) >= check_right_side_sprites(cub_file, 0))
				return (check_upper_side_sprites(cub_file, 0));
			else
				return (check_right_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -90 && (int)(cub_file->FOV * 180 / PI) % 360 > -180) // upper left
		{
			if (check_upper_side_sprites(cub_file, 0) >= check_left_side_sprites(cub_file, 0)) // было < 
				return (check_upper_side_sprites(cub_file, 0));
			else
				return (check_left_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -180 && (int)(cub_file->FOV * 180 / PI) % 360 > -270) // lower left
		{
			if (check_lower_side_sprites(cub_file, 0) >= check_left_side_sprites(cub_file, 0))
				return (check_lower_side_sprites(cub_file, 0));
			else
				return (check_left_side_sprites(cub_file, 0));
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -270 && (int)(cub_file->FOV * 180 / PI) % 360 > -360) // lower right
		{
			if (check_lower_side_sprites(cub_file, 0) >= check_right_side_sprites(cub_file, 0))
				return (check_lower_side_sprites(cub_file, 0));
			else
				return (check_right_side_sprites(cub_file, 0));
		}
	}
	return (0); // there is no sprite
}

/*****************************************************************************************************************************************/

int		get_n_sprite(t_parse *cub_file, int n_sprite)
{
	if (n_sprite <= 0)
		return (0);
	if (cub_file->FOV >= 0)
	{
		if ((int)(cub_file->FOV * 180 / PI) % 360 >= 0 && (int)(cub_file->FOV * 180 / PI) % 360 < 90) // lower right
		{
			if (check_lower_side_n_sprite(cub_file, 0, n_sprite) <= check_right_side_n_sprite(cub_file, 0, n_sprite))
			{
				if (check_lower_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_right_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 90 && (int)(cub_file->FOV * 180 / PI) % 360 < 180) // lower left
		{
			if (check_lower_side_n_sprite(cub_file, 0, n_sprite) <= check_left_side_n_sprite(cub_file, 0, n_sprite) * -1)
			{
				if (check_lower_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_left_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 180 && (int)(cub_file->FOV * 180 / PI) % 360 < 270) // upper left
		{
			if (check_upper_side_n_sprite(cub_file, 0, n_sprite) * -1 <= check_left_side_n_sprite(cub_file, 0, n_sprite) * -1) // было < 
			{
				if (check_upper_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_left_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 270 && (int)(cub_file->FOV * 180 / PI) % 360 < 360) // upper right
		{
			if (check_upper_side_n_sprite(cub_file, 0, n_sprite) * -1 <= check_right_side_n_sprite(cub_file, 0, n_sprite))
			{
				if (check_upper_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_right_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
	}
	else
	{
		if ((int)(cub_file->FOV * 180 / PI) % 360 <= 0 && (int)(cub_file->FOV * 180 / PI) % 360 > -90) // upper right
		{
			if (check_upper_side_n_sprite(cub_file, 0, n_sprite) * -1 <= check_right_side_n_sprite(cub_file, 0, n_sprite))
			{
				if (check_upper_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_right_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -90 && (int)(cub_file->FOV * 180 / PI) % 360 > -180) // upper left
		{
			if (check_upper_side_n_sprite(cub_file, 0, n_sprite) * -1 <= check_left_side_n_sprite(cub_file, 0, n_sprite) * -1) // было < 
			{
				if (check_upper_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_left_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_upper_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -180 && (int)(cub_file->FOV * 180 / PI) % 360 > -270) // lower left
		{
			if (check_lower_side_n_sprite(cub_file, 0, n_sprite) <= check_left_side_n_sprite(cub_file, 0, n_sprite) * -1)
			{
				if (check_lower_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_left_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_left_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
		else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -270 && (int)(cub_file->FOV * 180 / PI) % 360 > -360) // lower right
		{
			if (check_lower_side_n_sprite(cub_file, 0, n_sprite) <= check_right_side_n_sprite(cub_file, 0, n_sprite))
			{
				if (check_lower_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
			}
			else
			{
				if (check_right_side_n_sprite(cub_file, 0, n_sprite) == -1)
					return (check_lower_side_n_sprite(cub_file, 0, n_sprite));
				else
					return (check_right_side_n_sprite(cub_file, 0, n_sprite));
			}
		}
	}
	return (0); // there is no sprite
}