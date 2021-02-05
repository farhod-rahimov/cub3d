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

  #include "../cub3d.h"
 
void            my_mlx_pixel_put(t_parse *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int			ray_cast(t_parse **cub_file)
{
	long double tmp_len_of_c;
	long double tmp_len_of_c_nachalo;
	int tmp_x = 0;
	(*cub_file)->FOV = (*cub_file)->player_a - (PI / 6);
	char side;

	long double scale_texture_x;
	long double scale_texture_y;
	int stolbec_x;
	int stolbec_y = 0;
	char *color;
	int	color_int;
	int i_texture_y = 0;
	int lim;

	while ((*cub_file)->FOV <= (*cub_file)->player_a + (PI / 6) && tmp_x < (*cub_file)->Rx)
	{
		side = check_sides_walls_for_raycasting(cub_file);
		if ((*cub_file)->len_of_c < 0)
			(*cub_file)->len_of_c = (*cub_file)->len_of_c * -1;
		(*cub_file)->array_walls[tmp_x] = (*cub_file)->len_of_c;
		tmp_len_of_c = (*cub_file)->len_of_c / (*cub_file)->scale;
		tmp_len_of_c = (*cub_file)->Ry / (tmp_len_of_c * cosl((*cub_file)->player_a - (*cub_file)->FOV));
		tmp_len_of_c_nachalo = (*cub_file)->Ry / 2 - tmp_len_of_c / 2;
		if (side == 'N')
		{
			scale_texture_x = (float)(*cub_file)->width_north / (float)(*cub_file)->scale;
			(*cub_file)->addr_text = mlx_get_data_addr((*cub_file)->img_north, &(*cub_file)->bits_per_pixel_text, &(*cub_file)->line_length_text, &(*cub_file)->endian_text);
			scale_texture_y = (*cub_file)->height_north / tmp_len_of_c;
			stolbec_x = ((int)(*cub_file)->c_x % (*cub_file)->scale) * scale_texture_x;
			(*cub_file)->height = (*cub_file)->height_north;
		}
		else if (side == 'S')
		{
			scale_texture_x = (float)(*cub_file)->width_south / (float)(*cub_file)->scale;
			(*cub_file)->addr_text = mlx_get_data_addr((*cub_file)->img_south, &(*cub_file)->bits_per_pixel_text, &(*cub_file)->line_length_text, &(*cub_file)->endian_text);
			scale_texture_y = (*cub_file)->height_south / tmp_len_of_c;
			stolbec_x = (((*cub_file)->scale - (int)(*cub_file)->c_x % (*cub_file)->scale)) * scale_texture_x;
			(*cub_file)->height = (*cub_file)->height_south;
		}
		else if (side == 'W')
		{
			scale_texture_x = (float)(*cub_file)->width_west / (float)(*cub_file)->scale;
			(*cub_file)->addr_text = mlx_get_data_addr((*cub_file)->img_west, &(*cub_file)->bits_per_pixel_text, &(*cub_file)->line_length_text, &(*cub_file)->endian_text);
			scale_texture_y = (*cub_file)->height_west / tmp_len_of_c;
			stolbec_x = (((*cub_file)->scale - (int)(*cub_file)->c_y % (*cub_file)->scale)) * scale_texture_x;
			(*cub_file)->height = (*cub_file)->height_west;
		}
		else if (side == 'E')
		{
			scale_texture_x = (float)(*cub_file)->width_east / (float)(*cub_file)->scale;
			(*cub_file)->addr_text = mlx_get_data_addr((*cub_file)->img_east, &(*cub_file)->bits_per_pixel_text, &(*cub_file)->line_length_text, &(*cub_file)->endian_text);
			scale_texture_y = (*cub_file)->height_east / tmp_len_of_c;
			stolbec_x = ((int)(*cub_file)->c_y % (*cub_file)->scale) * scale_texture_x;
			(*cub_file)->height = (*cub_file)->height_east;
		}
		lim = ((*cub_file)->Ry / 2 + tmp_len_of_c / 2) - 1;
		if (tmp_len_of_c_nachalo < 0)
		{
			i_texture_y = (tmp_len_of_c - (*cub_file)->Ry) / 2;
			tmp_len_of_c_nachalo = 0;
			lim = (*cub_file)->Ry - 1;
		}
		while (stolbec_y < (*cub_file)->height && tmp_len_of_c_nachalo < lim)
		{
			stolbec_y = (int)(scale_texture_y * i_texture_y++);
			color = (*cub_file)->addr_text + (stolbec_x * 4 + stolbec_y * (*cub_file)->line_length_text);
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			my_mlx_pixel_put((*cub_file), tmp_x, tmp_len_of_c_nachalo, color_int);
			tmp_len_of_c_nachalo += 1;
		}
		stolbec_y = 0;
		i_texture_y = 0;
		tmp_x++;
		(*cub_file)->FOV += (PI / 3) / (*cub_file)->Rx;
	}
	ray_cast_sprites(cub_file);
	return (0);
}

int			ray_cast_sprites(t_parse **cub_file)
{
	int n = 0;
	
	if ((*cub_file)->num_of_sprites == 0)
		return (-1);
	(*cub_file)->addr_text = mlx_get_data_addr((*cub_file)->img_sprite, &(*cub_file)->bits_per_pixel_text, &(*cub_file)->line_length_text, &(*cub_file)->endian_text);
	// (*cub_file)->storona = 'O'; // в зависимости от первоначального взгяда игрока изменить данное значение
	(*cub_file)->FOV = (*cub_file)->player_a - (PI / 2);
	(*cub_file)->tmp_x = 0;
	// (*cub_file)->shirina = 0;
	match_sprites_as_not_drawn(cub_file);
	get_height_sprite_from_center(cub_file);
	sort_sprites(cub_file);
	
	while ((*cub_file)->FOV <= (*cub_file)->player_a + (PI / 2) && (*cub_file)->tmp_x < (*cub_file)->Rx * 3)
	{
		check_sides_sprites_for_raycasting(cub_file, 0);
		(*cub_file)->FOV += (PI / ((*cub_file)->Rx * 3)) * 1;
		(*cub_file)->tmp_x += 1;
	}
	complete_data_sprites(cub_file);

	(*cub_file)->FOV = (*cub_file)->player_a - (PI / 6);
	(*cub_file)->tmp_x = 0;

	while ((*cub_file)->FOV <= (*cub_file)->player_a + (PI / 6) && (*cub_file)->tmp_x < (*cub_file)->Rx - 1)
	{
		n = (*cub_file)->num_of_sprites;
		while (--n >= 0)
		{
			ft_draw_sprite(cub_file, n);
		}
		(*cub_file)->FOV += (PI / 3) / (*cub_file)->Rx;
		(*cub_file)->tmp_x++;
	}
	return (0);
}

void				match_sprites_as_not_drawn(t_parse **cub_file)
{
	int i = 0;

	while (i < (*cub_file)->num_of_sprites)
	{
		(*cub_file)->sprites[i][0] = -1; // scale_sprite_x
		(*cub_file)->sprites[i][1] = -1; // len_of_c (высота спрайта по его центру)
		(*cub_file)->sprites[i][4] = -1; // начало спарайта (угол в пи)
		(*cub_file)->sprites[i][5] = -1; // конец спарайта (угол в пи)
		(*cub_file)->sprites[i][6] = -1; // ширина спарайта (угол в пи)
		(*cub_file)->sprites[i][7] = -1; // len_of_c (высота спрайта по его центру для отрисовки)
		i++;
	}
}

void			get_height_sprite_from_center(t_parse **cub_file)
{
	long double a = 0;
	long double b = 0;
	int i = 0;

	while (i < (*cub_file)->num_of_sprites)
	{
		a = fabsl((long double)(*cub_file)->player_x - ((*cub_file)->sprites[i][3] * (*cub_file)->scale + (*cub_file)->scale / 2));
		b = fabsl((long double)(*cub_file)->player_y - ((*cub_file)->sprites[i][2] * (*cub_file)->scale + (*cub_file)->scale / 2));
		(*cub_file)->sprites[i][1] = sqrtl(a * a + b * b); // len_of_c (высота спрайта по его центру) // каждый раз меняется
		i++;
	}
}

void			sort_sprites(t_parse **cub_file)
{
	int a = 0;
	int b = 0;
	long double tmp = 0;
	while (a < (*cub_file)->num_of_sprites - 1)
	{
		while (b < (*cub_file)->num_of_sprites - 1)
		{
			if ((*cub_file)->sprites[b][1] > (*cub_file)->sprites[b + 1][1])
			{
				tmp = (*cub_file)->sprites[b][1];
				(*cub_file)->sprites[b][1] = (*cub_file)->sprites[b + 1][1];
				(*cub_file)->sprites[b + 1][1] = tmp;
				
				tmp = (*cub_file)->sprites[b][2];
				(*cub_file)->sprites[b][2] = (*cub_file)->sprites[b + 1][2];
				(*cub_file)->sprites[b + 1][2] = tmp;
				
				tmp = (*cub_file)->sprites[b][3];
				(*cub_file)->sprites[b][3] = (*cub_file)->sprites[b + 1][3];
				(*cub_file)->sprites[b + 1][3] = tmp;
			}
			b++;
		}
		b = 0;
		a++;
	}	
}
