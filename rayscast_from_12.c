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
	// static int q;
	int tmp_x;
	float	tmp_len_of_c;
	int	tmp_len_of_c_nachalo;;
	tmp_x = 0;
	tmp_len_of_c = 0;
	tmp_len_of_c_nachalo = 0;
	cub_file->len_of_c = 0;

	// float stolbec = 0;
	int stolbec_x = 0;
	int stolbec_y = 0;
	cub_file->FOV = cub_file->player_a - (PI / 6);

	// cub_file->addr_text = mlx_get_data_addr(cub_file->img_north, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
	char *color;
	int	color_int;
	float scale_texture;
	int i_texture = 0;
	// int sega = 0;
	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	{
		while (cub_file->len_of_c < cub_file->Ry && tmp_x < cub_file->Rx)
		{
			cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosf(cub_file->FOV);
			cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinf(cub_file->FOV);
			if (cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] != '0')
			{
				cub_file->len_of_c -= 0.01;
				tmp_len_of_c = cub_file->len_of_c / SCALE;
				if (tmp_len_of_c < 1)
					tmp_len_of_c = 1;
				tmp_len_of_c = cub_file->Ry / (tmp_len_of_c * cosf(cub_file->player_a - cub_file->FOV));
				tmp_len_of_c_nachalo = cub_file->Ry / 2 - tmp_len_of_c / 2;
				cub_file->c_x = tmp_x;
				// scale_texture = tmp_len_of_c / cub_file->height_north;
				scale_texture = cub_file->height_north / tmp_len_of_c;
				if (tmp_len_of_c_nachalo < 0)
				{
					tmp_len_of_c_nachalo = 0;
					while (tmp_len_of_c_nachalo < cub_file->Ry - 1)
					{
						stolbec_x = cub_file->c_x % cub_file->width_north;
						while ((stolbec_y < cub_file->height_north) && tmp_len_of_c_nachalo < cub_file->Ry - 1)
						{
							stolbec_y = (int)(scale_texture * i_texture++);
							// color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
							// color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
							// my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, color_int);
							my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, 0x000000); // black
							tmp_len_of_c_nachalo += 1;

						}
						stolbec_y = 0;
						i_texture = 0;
					}
				}
				else
				{
				// printf("1 cub_file->c_x / SCALE %d, cub_file->c_y / SCALE %d\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
					while (tmp_len_of_c_nachalo < cub_file->Ry / 2 + tmp_len_of_c / 2 - 1)
					{
						stolbec_x = cub_file->c_x % cub_file->width_north;
						while ((stolbec_y < cub_file->height_north) && (tmp_len_of_c_nachalo < cub_file->Ry / 2 + tmp_len_of_c / 2 - 1))
						{
							stolbec_y = (int)(scale_texture * i_texture++);
							if (((cub_file->c_x + 1) % SCALE == 0 && ((int)cub_file->c_y + 1) % SCALE != 0)
							|| ((cub_file->c_x + 1) % SCALE != 0 && ((int)cub_file->c_y + 1) % SCALE != 0))
							{
								// printf("c_x %d, c_y %d\n", cub_file->c_x, cub_file->c_y);
								// printf("c_x %% SCALE %d, c_y %% SCALE %d\n\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
								// cub_file->addr_text = mlx_get_data_addr(cub_file->img_east, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
								// color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
								my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, 0xffff00); // yellow
								// printf("c_x %d, c_y %d\n", cub_file->c_x + 1, cub_file->c_y + 1);
							}
							else if (((cub_file->c_x + 1) % SCALE != 0 && ((int)cub_file->c_y + 1) % SCALE == 0)
							|| ((cub_file->c_x + 1) % SCALE == 0 && ((int)cub_file->c_y + 1) % SCALE == 0))
							{
								// printf("c_x %d, c_y %d\n", cub_file->c_x, cub_file->c_y);
								// printf("c_x %% SCALE %d, c_y %% SCALE %d\n\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
								cub_file->addr_text = mlx_get_data_addr(cub_file->img_north, &cub_file->bits_per_pixel_text, &cub_file->line_length_text, &cub_file->endian_text);
								color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
								color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
								my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, color_int);
							}
							// else
							// {
							// 	// printf("c_x %% SCALE %d, c_y %% SCALE %d\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
							// 	my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, 0xff0000); // red
							// }
							
							// color = cub_file->addr_text + (stolbec_x * 4 + stolbec_y * cub_file->line_length_text);
							// color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
							// my_mlx_pixel_put(cub_file, (int)cub_file->c_x, tmp_len_of_c_nachalo, color_int);
							tmp_len_of_c_nachalo += 1;
						}
						stolbec_y = 0;
						i_texture = 0;
					}
				}
				tmp_x++;
				break ;
			}
			cub_file->len_of_c += 0.01;
		}
		cub_file->len_of_c = 0;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
	return (0);
}