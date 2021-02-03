/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/19 09:18: 3by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	check_upper_side_sprites(t_parse **cub_file, int i) // ok
{
	int n;
	(*cub_file)->len_of_c = 0;

	while (1)
	{
		n = 0;
		(*cub_file)->len_of_c = (((*cub_file)->scale * i++ + ((((*cub_file)->player_y % (*cub_file)->scale) + (*cub_file)->scale / 2) + 1)) / sinl((*cub_file)->FOV)); // в OLDUS вместо  + 1 стоит -1
		(*cub_file)->c_x = (*cub_file)->player_x - (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y - (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;

		if ((*cub_file)->c_x > (*cub_file)->map_x * (*cub_file)->scale || (*cub_file)->c_y > (*cub_file)->map_y * (*cub_file)->scale ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
			return ;

		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == '2')
		{
			while (n < (*cub_file)->num_of_sprites)
			{
				if (((int)(*cub_file)->sprites[n][2] == (int)(*cub_file)->c_y / (*cub_file)->scale) && ((int)(*cub_file)->sprites[n][3] == (int)(*cub_file)->c_x / (*cub_file)->scale)) // scale sprite_x
				{
					if ((*cub_file)->sprites[n][4] == -1.0) // начало спрайта в ПИ
					{
						(*cub_file)->sprites[n][4] = (*cub_file)->FOV;
					}
					else
					{
						(*cub_file)->sprites[n][5] = (*cub_file)->FOV;// конец спрайта в ПИ
					}
					break ;
				}
				n++;
			}
		}
		else if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == ' ')
			return ;
	}
}

void	check_lower_side_sprites(t_parse **cub_file, int i) // ok
{
	int n;
	(*cub_file)->len_of_c = 0;

	while (1)
	{
		n = 0;
		(*cub_file)->len_of_c = ((*cub_file)->scale * i++ + ((*cub_file)->scale - ((*cub_file)->player_y % (*cub_file)->scale) + (*cub_file)->scale / 2)) / sinl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x + (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y + (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;

		if ((*cub_file)->c_x > (*cub_file)->map_x * (*cub_file)->scale || (*cub_file)->c_y > (*cub_file)->map_y * (*cub_file)->scale ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
			return ;

		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == '2')
		{
			while (n < (*cub_file)->num_of_sprites)
			{
				if (((int)(*cub_file)->sprites[n][2] == (int)(*cub_file)->c_y / (*cub_file)->scale) && ((int)(*cub_file)->sprites[n][3] == (int)(*cub_file)->c_x / (*cub_file)->scale)) // scale sprite_x
				{
					if ((*cub_file)->sprites[n][4] == -1.0) // начало спрайта в ПИ
					{
						(*cub_file)->sprites[n][4] = (*cub_file)->FOV;
					}
					else
					{
						(*cub_file)->sprites[n][5] = (*cub_file)->FOV;// конец спрайта в ПИ
					}
					break ;
				}
				n++;
			}
		}
		else if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == ' ')
			return ;
	}
}

void	check_left_side_sprites(t_parse **cub_file, int i) // ok
{
	int n;
	(*cub_file)->len_of_c = 0;

	while (1)
	{
		n = 0;
		(*cub_file)->len_of_c  = ((*cub_file)->scale * i++ + ((((*cub_file)->player_x % (*cub_file)->scale) + (*cub_file)->scale / 2 ) + 1)) / cosl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x - (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y - (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;
		
		if ((*cub_file)->c_x > (*cub_file)->map_x * (*cub_file)->scale || (*cub_file)->c_y > (*cub_file)->map_y * (*cub_file)->scale ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
			return ;

		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == '2')
		{
			while (n < (*cub_file)->num_of_sprites)
			{
				if (((int)(*cub_file)->sprites[n][2] == (int)(*cub_file)->c_y / (*cub_file)->scale) && ((int)(*cub_file)->sprites[n][3] == (int)(*cub_file)->c_x / (*cub_file)->scale)) // scale sprite_x
				{
					if ((*cub_file)->sprites[n][4] == -1.0) // начало спрайта в ПИ
					{
						(*cub_file)->sprites[n][4] = (*cub_file)->FOV;
					}
					else
					{
						(*cub_file)->sprites[n][5] = (*cub_file)->FOV;// конец спрайта в ПИ
					}
					break ;
				}
				n++;
			}
		}
		else if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == ' ')
			return ;
	}
}

void	check_right_side_sprites(t_parse **cub_file, int i) // ok
{
	(*cub_file)->len_of_c = 0;
	int n;

	while (1)
	{	
		n = 0;
		(*cub_file)->len_of_c = ((*cub_file)->scale * i++ + ((*cub_file)->scale - ((*cub_file)->player_x % (*cub_file)->scale) + (*cub_file)->scale / 2)) / cosl((*cub_file)->FOV);
		(*cub_file)->c_x = (*cub_file)->player_x + (*cub_file)->len_of_c * cosl((*cub_file)->FOV) + 0.1;
		(*cub_file)->c_y = (*cub_file)->player_y + (*cub_file)->len_of_c * sinl((*cub_file)->FOV) + 0.1;

		if ((*cub_file)->c_x > (*cub_file)->map_x * (*cub_file)->scale || (*cub_file)->c_y > (*cub_file)->map_y * (*cub_file)->scale ||
		(*cub_file)->c_x < 0 || (*cub_file)->c_y < 0)
			return ;

		if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == '2')
		{
			while (n < (*cub_file)->num_of_sprites)
			{
				if (((int)(*cub_file)->sprites[n][2] == (int)(*cub_file)->c_y / (*cub_file)->scale) && ((int)(*cub_file)->sprites[n][3] == (int)(*cub_file)->c_x / (*cub_file)->scale)) // scale sprite_x
				{
					if ((*cub_file)->sprites[n][4] == -1.0) // начало спрайта в ПИ
					{
						(*cub_file)->sprites[n][4] = (*cub_file)->FOV;
					}
					else
					{
						(*cub_file)->sprites[n][5] = (*cub_file)->FOV;// конец спрайта в ПИ
					}
					break ;
				}
				n++;
			}
		}
		else if ((*cub_file)->map2d[(int)(*cub_file)->c_y][(int)(*cub_file)->c_x] == ' ')
			return ;
	}
}

void				complete_data_sprites(t_parse **cub_file) // ok
{
	int n = 0;

	while (n < (*cub_file)->num_of_sprites)
	{
		(*cub_file)->sprites[n][6] = fabsl((*cub_file)->sprites[n][5] - (*cub_file)->sprites[n][4]); // ширина
		(*cub_file)->sprites[n][0] = (float)(*cub_file)->width_sprite / (*cub_file)->sprites[n][6]; // scale_texture_x
		(*cub_file)->sprites[n][7] = (*cub_file)->Ry / ((*cub_file)->sprites[n][1] / (*cub_file)->scale); //// len_of_c (высота спрайта по его центру для отрисовки)
		n++;
	}
}

void		ft_draw_sprite(t_parse **cub_file, int n) // ok
{
	long double scale_texture_y;
	int stolbec_x = 0;
	int stolbec_y = 0;
	char *color;
	int	color_int;
	int i_texture_y = 0;
	long double tmp_len_of_c_nachalo;
	long double lim;

	if ((*cub_file)->sprites[n][1] > (*cub_file)->array_walls[(*cub_file)->tmp_x])
		return ;
	if ((*cub_file)->FOV < (*cub_file)->sprites[n][4] || (*cub_file)->FOV > (*cub_file)->sprites[n][5] || (*cub_file)->sprites[n][4] == -1 || (*cub_file)->sprites[n][5] == -1)
		return ;
	stolbec_x = fabsl((*cub_file)->sprites[n][5] - (*cub_file)->FOV) * (*cub_file)->sprites[n][0];

	tmp_len_of_c_nachalo = (*cub_file)->Ry / 2 - (*cub_file)->sprites[n][7] / 2;
	scale_texture_y = (*cub_file)->height_sprite / (*cub_file)->sprites[n][7];;
	lim = ((*cub_file)->Ry / 2 + (*cub_file)->sprites[n][7] / 2) - 1;
	if (tmp_len_of_c_nachalo < 0)
	{
		i_texture_y = ((*cub_file)->sprites[n][7] - (*cub_file)->Ry) / 2;
		tmp_len_of_c_nachalo = 0;
		lim = (*cub_file)->Ry - 1;
	}
	while (stolbec_y < (*cub_file)->height_sprite && tmp_len_of_c_nachalo < lim)
	{
		stolbec_y = (int)(scale_texture_y * i_texture_y++);
		color = (*cub_file)->addr_text + (stolbec_x * 4 + stolbec_y * (*cub_file)->line_length_text);
		color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
		if (color_int != 0)
			my_mlx_pixel_put((*cub_file), (*cub_file)->tmp_x, tmp_len_of_c_nachalo, color_int);
		tmp_len_of_c_nachalo += 1;
	}
}