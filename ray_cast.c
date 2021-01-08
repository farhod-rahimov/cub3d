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
 
void            my_mlx_pixel_put(t_parse *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int			ray_cast(t_parse *cub_file)
{
	float tmp_len_of_c;
	float tmp_len_of_c_nachalo;
	int tmp_x = 0;
	cub_file->FOV = cub_file->player_a - (PI / 6);
	
	char side;
	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	{
		side = check_sides_for_raycsting(cub_file);
		if (cub_file->len_of_c < 0)
			cub_file->len_of_c = cub_file->len_of_c * -1;
		tmp_len_of_c = cub_file->len_of_c / SCALE;
		tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosf(cub_file->player_a - cub_file->FOV));
		tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
		if (tmp_len_of_c_nachalo < 0)
		{
			tmp_len_of_c_nachalo = 0;
			while (tmp_len_of_c_nachalo < cub_file->Ry - 1)
			{
				my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, 0xffffff); // white
				tmp_len_of_c_nachalo++;
			}
		}
		else
		{
			while (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1)
			{
				if (side == 'N')
					my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, 0x000000); // black
				else if (side == 'S')
					my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, 0xff0000); // red
				else if (side == 'W')
					my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, 0xf2ff03); // yellow
				else if (side == 'E')
					my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, 0xff9e03); // orange
				tmp_len_of_c_nachalo++;
			}
		}
		tmp_x++;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	return (0);
}