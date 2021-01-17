/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/16 17:37:05 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
#include "./cub3d.h"

long double check_upper_side_sprites(t_parse *cub_file, int i)
{
	int num_sprite = 0;
	cub_file->len_of_c = 0;
	// static int ia;
	while (1) // UPPER
	{
		cub_file->len_of_c = ((SCALE * i++ + ((cub_file->player_y % SCALE) + 1)) / sinl(cub_file->FOV));
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				num_sprite++;
			}
			else
				break ;
		}
	}
	// if (num_sprite > 1)
		// printf("numUU %d, i %d\n-----\n", num_sprite, ia++);
	return (num_sprite);
}

long double check_lower_side_sprites(t_parse *cub_file, int i)
{
	int num_sprite = 0;
	cub_file->len_of_c = 0;
	while (1) // LOWER
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_y % SCALE))) / sinl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -180)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				num_sprite++;
			}
			else
				break ;
		}
	}
	return (num_sprite);
}

long double check_left_side_sprites(t_parse *cub_file, int i)
{
	int num_sprite = 0;
	cub_file->len_of_c = 0;
	while (1) // LEFT
	{
		cub_file->len_of_c = (SCALE * i++ + ((cub_file->player_x % SCALE) + 1)) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) >= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				num_sprite++;
			}
			else
				break ;
		}
	}
	return (num_sprite);
}

long double check_right_side_sprites(t_parse *cub_file, int i)
{
	int num_sprite = 0;
	cub_file->len_of_c = 0;

	while (1) // RIGHT
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_x % SCALE))) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -270)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 270))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				num_sprite++;
			}
			else
				break ;
		}
	}
	return (num_sprite);
}

/**************************************************************************************************************************/

long double check_upper_side_n_sprite(t_parse *cub_file, int i, int n_sprite)
{
	cub_file->len_of_c = 0;
	cub_file->side = 'N';

	while (1) // UPPER
	{
		cub_file->len_of_c = ((SCALE * i++ + ((cub_file->player_y % SCALE) + 1)) / sinl(cub_file->FOV));
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				n_sprite--;
				if (n_sprite == 0)
					return (cub_file->len_of_c);
			}
			else
			{
				cub_file->len_of_c = cub_file->Rx * -10;
				break ;
			}
		}
	}
	return (-1);
}

long double check_lower_side_n_sprite(t_parse *cub_file, int i, int n_sprite)
{
	cub_file->len_of_c = 0;
	cub_file->side = 'S';

	while (1) // LOWER
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_y % SCALE))) / sinl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -180)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				n_sprite--;
				if (n_sprite == 0)
					return (cub_file->len_of_c);
			}
			else
			{
				cub_file->len_of_c = cub_file->Rx * -10;
				break ;
			}
		}
	}
	return (-1);
}

long double check_left_side_n_sprite(t_parse *cub_file, int i, int n_sprite)
{
	cub_file->len_of_c = 0;
	cub_file->side = 'W';

	while (1) // LEFT
	{
		cub_file->len_of_c = (SCALE * i++ + ((cub_file->player_x % SCALE) + 1)) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) >= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				n_sprite--;
				if (n_sprite == 0)
					return (cub_file->len_of_c);
			}
			else
			{
				cub_file->len_of_c = cub_file->Rx * -10;
				break ;
			}
		}
	}
	return (-1);
}

long double check_right_side_n_sprite(t_parse *cub_file, int i, int n_sprite)
{
	cub_file->len_of_c = 0;
	cub_file->side = 'E';

	while (1) // RIGHT
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_x % SCALE))) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -270)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 270))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '2')
			{
				n_sprite--;
				if (n_sprite == 0)
					return (cub_file->len_of_c);
			}
			else
			{
				cub_file->len_of_c = cub_file->Rx * 10;
				break ;
			}
		}
	}
	return (-1);
}