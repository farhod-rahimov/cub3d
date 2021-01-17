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
	long double tmp_len_of_c;
	long double tmp_len_of_c_nachalo;
	int tmp_x = 0;
	cub_file->FOV = cub_file->player_a - (PI / 6);
	char side;

	long double scale_texture;
	int stolbec_x;
	int stolbec_y;
	char *color;
	int	color_int;
	int i_texture = 0;
	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	{
		side = check_sides_walls_for_raycsting(cub_file);
		if (cub_file->len_of_c < 0)
			cub_file->len_of_c = cub_file->len_of_c * -1;
		tmp_len_of_c = cub_file->len_of_c / SCALE;
		tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosl(cub_file->player_a - cub_file->FOV));
		tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
		if (tmp_len_of_c_nachalo < 0)
		{
			tmp_len_of_c = cub_file->Ry;
			tmp_len_of_c_nachalo = 0;
		}
		if (side == 'N')
		{
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_north, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture = cub_file->height_north / tmp_len_of_c;
			stolbec_x = (int)cub_file->c_x % cub_file->width_north;
			cub_file->height = cub_file->height_north;
			// printf("scale_texture N %f\n", scale_texture);
		}
		else if (side == 'S')
		{
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_south, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture = cub_file->height_south / tmp_len_of_c;
			stolbec_x = (int)cub_file->c_x % cub_file->width_south;
			cub_file->height = cub_file->height_south;
		}
		else if (side == 'W')
		{
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_west, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture = cub_file->height_west / tmp_len_of_c;
			stolbec_x = (int)cub_file->c_y % cub_file->width_west;
			cub_file->height = cub_file->height_west;
		}
		else if (side == 'E')
		{
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_east, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture = cub_file->height_east / tmp_len_of_c;
			stolbec_x = (int)cub_file->c_y % cub_file->width_east;
			cub_file->height = cub_file->height_east;
		}
		while ((stolbec_y < cub_file->height) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
		{
			stolbec_y = (int)(scale_texture * i_texture++);
			color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, color_int);
			tmp_len_of_c_nachalo += 1;
		}
		stolbec_y = 0;
		i_texture = 0;
		tmp_x++;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	ray_cast_sprites(cub_file);
	return (0);
}

int					ray_cast_sprites(t_parse *cub_file)
{
	long double tmp_len_of_c;
	long double tmp_len_of_c_nachalo;
	long double tmp_tmp_len_of_c_nachalo;
	int tmp_x = 0;
	// char side;

	long double scale_sprite;
	int stolbec_x;
	int stolbec_y;
	char *color;
	int	color_int;
	int i_sprite = 0;
	int i = 0;
	if ((tmp_x = check_sides_sprites_for_raycasting(cub_file)) == -1)
		return (-1); // there is no sprite
	printf ("sss %d\n", tmp_x);
	if (cub_file->len_of_c < 0)
		cub_file->len_of_c = cub_file->len_of_c * -1;
	tmp_len_of_c = cub_file->len_of_c / SCALE;
	tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosl(cub_file->player_a - cub_file->FOV));
	tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
	tmp_tmp_len_of_c_nachalo = tmp_len_of_c_nachalo;
	if (tmp_len_of_c_nachalo < 0)
	{
		tmp_len_of_c = cub_file->Ry;
		tmp_len_of_c_nachalo = 0;
	}
	cub_file->addr_text = mlx_get_data_addr(cub_file->img_sprite, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
	scale_sprite = cub_file->height_sprite / tmp_len_of_c;
	stolbec_x = i;
	while (cub_file->FOV <= cub_file->player_a + (PI / 6) && i <= cub_file->width_sprite)
	{
		while ((stolbec_y < cub_file->height_sprite) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
		{
			stolbec_y = (int)(scale_sprite * i_sprite++);
			color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, color_int);
			tmp_len_of_c_nachalo += 1;
		}
		tmp_len_of_c_nachalo = tmp_tmp_len_of_c_nachalo;
		stolbec_y = 0;
		stolbec_x++;;
		i_sprite = 0;
		tmp_x++;
		i++;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	return (0);
}