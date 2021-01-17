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

	long double scale_texture_x;
	long double scale_texture_y;
	int stolbec_x;
	int stolbec_y;
	char *color;
	int	color_int;
	int i_texture_y = 0;

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
			scale_texture_x = (float)cub_file->width_north / (float)SCALE;
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_north, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture_y = cub_file->height_north / tmp_len_of_c;
			stolbec_x = ((int)cub_file->c_x % SCALE) * scale_texture_x;
			cub_file->height = cub_file->height_north;
		}
		else if (side == 'S')
		{
			scale_texture_x = (float)cub_file->width_south / (float)SCALE;
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_south, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture_y = cub_file->height_south / tmp_len_of_c;
			stolbec_x = ((int)cub_file->c_x % SCALE) * scale_texture_x;
			cub_file->height = cub_file->height_south;
		}
		else if (side == 'W')
		{
			scale_texture_x = (float)cub_file->width_west / (float)SCALE;
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_west, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture_y = cub_file->height_west / tmp_len_of_c;
			stolbec_x = ((int)cub_file->c_y % SCALE) * scale_texture_x;
			cub_file->height = cub_file->height_west;
		}
		else if (side == 'E')
		{
			scale_texture_x = (float)cub_file->width_east / (float)SCALE;
			cub_file->addr_text = mlx_get_data_addr(cub_file->img_east, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
			scale_texture_y = cub_file->height_east / tmp_len_of_c;
			stolbec_x = ((int)cub_file->c_y % SCALE) * scale_texture_x;
			cub_file->height = cub_file->height_east;
		}
		while ((stolbec_y < cub_file->height) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
		{
			stolbec_y = (int)(scale_texture_y * i_texture_y++);
			color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, color_int);
			tmp_len_of_c_nachalo += 1;
		}
		stolbec_y = 0;
		i_texture_y = 0;
		tmp_x++;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	ray_cast_sprites(cub_file);
	return (0);
}


// int				ray_cast_sprites(t_parse *cub_file)
// {
// 	long double tmp_len_of_c;
// 	long double tmp_len_of_c_nachalo;
// 	int tmp_x = 0;
// 	cub_file->FOV = cub_file->player_a - (PI / 6);
// 	char side;

// 	long double scale_texture_x;
// 	long double scale_texture_y;
// 	int stolbec_x;
// 	int stolbec_y;
// 	char *color;
// 	int	color_int;
// 	int i_texture_y = 0;

// 	scale_texture_x = (float)cub_file->width_north / (float)SCALE;
// 	cub_file->addr_text = mlx_get_data_addr(cub_file->img_sprite, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
// 	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
// 	{
// 		side = check_sides_walls_for_raycsting(cub_file);
// 		if (cub_file->len_of_c < 0)
// 			cub_file->len_of_c = cub_file->len_of_c * -1;
// 		tmp_len_of_c = cub_file->len_of_c / SCALE;
// 		tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosl(cub_file->player_a - cub_file->FOV));
// 		scale_texture_y = cub_file->height_sprite / tmp_len_of_c;
// 		tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
// 		if (tmp_len_of_c_nachalo < 0)
// 		{
// 			tmp_len_of_c = cub_file->Ry;
// 			tmp_len_of_c_nachalo = 0;
// 		}
// 		if (side == 'N' || side == 'S')
// 			stolbec_x = ((int)cub_file->c_x % SCALE) * scale_texture_x;
// 		else if (side == 'W' || side == 'E')
// 			stolbec_x = ((int)cub_file->c_y % SCALE) * scale_texture_x;
// 		while ((stolbec_y < cub_file->height_sprite) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
// 		{
// 			stolbec_y = (int)(scale_texture_y * i_texture_y++);
// 			color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
// 			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
// 			my_mlx_pixel_put(cub_file, tmp_x, tmp_len_of_c_nachalo, color_int);
// 			tmp_len_of_c_nachalo += 1;
// 		}
// 		stolbec_y = 0;
// 		i_texture_y = 0;
// 		tmp_x++;
// 		cub_file->FOV += (PI / 3) / cub_file->Rx;
// 	}
// 	return (0);
// }

int					ray_cast_sprites(t_parse *cub_file)
{	long double tmp_len_of_c;
	long double tmp_len_of_c_nachalo;
	long double tmp_len_of_c_nachalo2;
	int tmp_x = 0;
	int tmp_x2 = 0;
	cub_file->FOV = cub_file->player_a - (PI / 6);

	long double scale_texture_x;
	long double scale_texture_y;
	int stolbec_x;
	int stolbec_y = 0;
	char *color;
	int	color_int;
	int i_texture_y = 0;
	int i_texture_x = 0;
	
	int num_of_sprites = 0;
	scale_texture_x = (float)cub_file->width_sprite / (float)SCALE;
	stolbec_x = 0;
	cub_file->addr_text = mlx_get_data_addr(cub_file->img_sprite, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
	// int quququ = 0;
	char **tmp_map2d;
	if ((tmp_map2d = ft_copy_map2d(cub_file->map2d, cub_file)) == NULL)
		return (-1);
	while (cub_file->FOV <= cub_file->player_a + (PI / 6) /*&& i <= cub_file->width_sprite*/ /*&& cub_file->sprite_start < cub_file->sprite_end*/)
	{
		tmp_x2 = tmp_x;
		num_of_sprites = check_num_of_sprites(cub_file);
		while (num_of_sprites > 0)
		{
			// printf("num %d\n", num_of_sprites);
			tmp_x = tmp_x2;
			// printf ("num_of-sprites %d\n", num_of_sprites);
			if (get_n_sprite(cub_file, num_of_sprites) == 0)
				break ;
			if (cub_file->len_of_c < 0)
				cub_file->len_of_c *= -1;
			remove_sprite_from_map2d(cub_file);
			// printf("c_y %d, c_x %d\n", (int)cub_file->c_y, (int)cub_file->c_x);
			// printf("c_y / SCALE %d, c_x / SCALE %d\n--------------\n", (int)cub_file->c_y / SCALE, (int)cub_file->c_x / SCALE);
			// break ;
			tmp_len_of_c = cub_file->len_of_c / SCALE;
			tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosl(cub_file->player_a - cub_file->FOV));
			tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
			if (tmp_len_of_c_nachalo < 0)
			{
				tmp_len_of_c = cub_file->Ry;
				tmp_len_of_c_nachalo = 0;
			}
			tmp_len_of_c_nachalo2 = tmp_len_of_c_nachalo;
			// printf("tmp_len_of_c_nachalo %Lf\n", tmp_len_of_c_nachalo);
			scale_texture_y = cub_file->height_sprite / tmp_len_of_c;
			// printf("scale_text_y %Lf\n", scale_texture_y);
			// stolbec_x = ((int)cub_file->c_x % SCALE) * scale_texture_x;
			// stolbec_x = (tmp_x % cub_file->width_sprite);
			// stolbec_x = ((int)cub_file->c_x % SCALE) * scale_texture_x;
			stolbec_x = (int)scale_texture_x;
			while (stolbec_x < cub_file->width_sprite && tmp_x < cub_file->Rx - 1)
			{
				while ((stolbec_y < cub_file->height_sprite) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
				{
					stolbec_y = (int)(scale_texture_y * i_texture_y++);
					color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
					color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
					if (color_int != 0x000000)
						my_mlx_pixel_put(cub_file, tmp_x, (int)tmp_len_of_c_nachalo, color_int);
					// my_mlx_pixel_put(cub_file, tmp_x, (int)tmp_len_of_c_nachalo, 0x000000);
					tmp_len_of_c_nachalo += 1;
					// printf("quququ %d\n", quququ++);
				}
				stolbec_y = 0;
				i_texture_y = 0;
				stolbec_x = scale_texture_x * ++i_texture_x;
				tmp_x++;
				tmp_len_of_c_nachalo = tmp_len_of_c_nachalo2;
			}
			num_of_sprites--;
		}
		tmp_x++;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	ft_free_map2d(cub_file->map2d, cub_file);
	if ((cub_file->map2d = ft_copy_map2d(tmp_map2d, cub_file)) == NULL)
		return (-1);
	ft_free_map2d(tmp_map2d, cub_file);
	return (0);
}

void remove_sprite_from_map2d(t_parse *cub_file)
{
	int x;
	int y;

	// x = 0;
	// y = 0;
	// printf("map2d before removing sprite\n");
	// while (y < cub_file->map_y * SCALE)
	// {
	// 	printf("%s\n", cub_file->map2d[y]);
	// 	y++;
	// }

	x = (int)cub_file->c_x / SCALE * SCALE;
	y = (int)cub_file->c_y / SCALE * SCALE;

	while (y < ((int)cub_file->c_y / SCALE * SCALE) + SCALE)
	{
		while (x < ((int)cub_file->c_x / SCALE * SCALE) + SCALE)
		{
			cub_file->map2d[y][x] = '0';
			x++;
		}
		x = (int)cub_file->c_x / SCALE * SCALE;
		y++;
	}
	
	// y = 0;
	// printf("map2d after removing sprite\n");
	// while (y < cub_file->map_y * SCALE)
	// {
	// 	printf("%s\n", cub_file->map2d[y]);
	// 	y++;
	// }
}

// int					ray_cast_sprites(t_parse *cub_file)
// {
// 	long double tmp_len_of_c;
// 	long double tmp_len_of_c_nachalo;
// 	long double tmp_tmp_len_of_c_nachalo;
// 	int tmp_x = 0;
// 	// char side;

// 	long double scale_sprite;
// 	int stolbec_x = 0;
// 	int stolbec_y = 0;
// 	char *color;
// 	int	color_int;
// 	int i_sprite = 0;
// 	int i = 0;
// 	if ((tmp_x = check_sides_sprites_for_raycasting(cub_file)) == 0)
// 		return (-1); // there is no sprite
// 	// printf("start %d\n", cub_file->sprite_start);
// 	// printf("end %d\n", cub_file->sprite_end);
// 	if (cub_file->sprite_len_of_c < 0)
// 		cub_file->sprite_len_of_c = cub_file->sprite_len_of_c * -1;
// 	tmp_len_of_c = cub_file->sprite_len_of_c / SCALE;
// 	tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosl(cub_file->player_a - cub_file->FOV));
// 	tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
// 	if (tmp_len_of_c_nachalo < 0)
// 	{
// 		tmp_len_of_c = cub_file->Ry;
// 		tmp_len_of_c_nachalo = 0;
// 	}
// 	// printf("len_of_c_nachalo %Lf\n------\n\n", tmp_len_of_c_nachalo);
// 	tmp_tmp_len_of_c_nachalo = tmp_len_of_c_nachalo;
// 	cub_file->addr_text = mlx_get_data_addr(cub_file->img_sprite, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
// 	scale_sprite = cub_file->height_sprite / tmp_len_of_c;
// 	stolbec_x = i;
// 	cub_file->FOV = cub_file->player_a - (PI / 6);
// 	while (cub_file->FOV <= cub_file->player_a + (PI / 6) /*&& i <= cub_file->width_sprite*/ && cub_file->sprite_start < cub_file->sprite_end)
// 	{
// 		while ((stolbec_y < cub_file->height_sprite) && (tmp_len_of_c_nachalo < (cub_file->Ry / 2 + tmp_len_of_c / 2) - 1))
// 		{
// 			stolbec_y = (int)(scale_sprite * i_sprite++);
// 			color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
// 			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
// 			if (color_int != 0)
// 				my_mlx_pixel_put(cub_file, cub_file->sprite_start, (int)tmp_len_of_c_nachalo, color_int);
// 			tmp_len_of_c_nachalo += 1;
// 		}
// 		tmp_len_of_c_nachalo = tmp_tmp_len_of_c_nachalo;
// 		stolbec_y = 0;
// 		if (stolbec_x++ > cub_file->width_sprite)
// 			stolbec_x = 0;
// 		i_sprite = 0;
// 		tmp_x++;
// 		i++;
// 		cub_file->sprite_start++;
// 		cub_file->FOV += (PI / 3) / cub_file->Rx;
// 	}
// 	return (0);
// }