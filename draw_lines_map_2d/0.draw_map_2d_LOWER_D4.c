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
#include "../cub3d.h"
// gcc test.c libmlx.dylib -framework OpenGl -framework Appkit

void draw_map_2d(t_parse *cub_file, int x, int y)
{
	while (cub_file->map2d[y][x])
	{
		while (cub_file->map2d[y][x])
		{
			if (cub_file->map2d[y][x] == '1' || cub_file->map2d[y][x] == '6' || cub_file->map2d[y][x] == '7' || cub_file->map2d[y][x] == '8' || cub_file->map2d[y][x] == '9')
				my_mlx_pixel_put(cub_file, x, y, 0x074517); // dark green
			// else if (cub_file->map2d[y][x] == 'N' || cub_file->map2d[y][x] == 'S'
			// || cub_file->map2d[y][x] == 'E' || cub_file->map2d[y][x] == 'W')
			// 	my_mlx_pixel_put(cub_file, x, y, 0x7a0505); // dark red // на карте больше нет этих букв, удали это
			else if (cub_file->map2d[y][x] == '2')
				my_mlx_pixel_put(cub_file, x, y, 0x5c5a19); // dark yellow
			else if (cub_file->map2d[y][x] == ' ')
				my_mlx_pixel_put(cub_file, x, y, 0x0e5859); // dark blue
			x++;
		}
		x = 0;
		y++;
	}
	// // printf("FOV %f\n", cub_file->FOV);
	// cub_file->len_of_c = 0;   // бросание лучей на карте
	// cub_file->FOV = cub_file->player_a - (PI / 6);
	// while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	// {
	// 	while (cub_file->len_of_c < cub_file->Ry + 100)
	// 	{
	// 		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cos(cub_file->FOV);
	// 		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sin(cub_file->FOV);
	// 		// my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0x3d082c);
	// 		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	// 		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0'
	// 		&& cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != cub_file->p_of_view) // cub_file->p_of_view не надо. убери это
	// 		{
	// 			// printf("cub_file->c_x %d, cub_file->c_y %d\n", cub_file->c_x + 1, cub_file->c_y + 1);
	// 			// printf("1 cub_file->c_x / SCALE %d, cub_file->c_y / SCALE %d\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
	// 			// printf("0 cub_file->c_x / SCALE %d, cub_file->c_y / SCALE %d\n\n", cub_file->c_x % SCALE, cub_file->c_y % SCALE); // wrong
	// 				break ;
	// 		}
	// 		cub_file->len_of_c += 1;
	// 	}
	// 	cub_file->len_of_c = 0;
	// 	cub_file->FOV += PI / 180;
	// 	cub_file->FOV += PI / 180 / 18;
	// }
	// printf("player_a %f\n", cub_file->player_a);
	// printf("%f\n", cub_file->player_a * 180 / PI);

	int a = 0; // draw player_position
	int b = 0;
	while (b < 5)
	{
		while (a < 5)
		{
			cub_file->c_x = cub_file->player_x + a;
			my_mlx_pixel_put(cub_file, (int)cub_file->c_x, cub_file->player_y + b, 0xffffff);
			a++;
		}
		a = 0;
		b++;
	}

	while (a < 20)
	{
		cub_file->c_x = cub_file->player_x + a * cos(cub_file->player_a);
		cub_file->c_y = cub_file->player_y + a * sin(cub_file->player_a);
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0x00ff00);
		a++;
	}

	int i = 0;
	// int hit_x = 0;
	// float max_len_of_c = sqrt(cub_file->map_x * SCALE * cub_file->map_x * SCALE + cub_file->map_y * SCALE * cub_file->map_y * SCALE);

	cub_file->len_of_c = 0;
	// cub_file->FOV = cub_file->player_a - (PI / 6);
	cub_file->FOV = cub_file->player_a;
	cub_file->player_x = 4;
	cub_file->player_y = 5;
	// int iii = 0;
	// while (cub_file->FOV <= cub_file->player_a + (PI / 6)) // hit_y
	// {
	while (1) // LOWER
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_y % SCALE))) / sin(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cos(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sin(cub_file->FOV) + 0.1;
			// cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] = 'K';
			// y = 0;
			// while (y <= (cub_file)->map_y * SCALE)
			// {
			// 	printf("%s\n", (cub_file)->map2d[y]);
			// 	y++;
			// }
			// break ;
		// printf("len_of_c %f, c_x %f, c_y %f, FOV %f\n", cub_file->len_of_c, cub_file->c_x, cub_file->c_y, cub_file->FOV * 180 / PI);
		// cub_file->map2d[cub_file->player_y][cub_file->player_x] = 'N';
		// cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] = 'K';
		// y = 0;
		// while (y <= (cub_file)->map_y * SCALE)
		// {
		// 	printf("%s\n", (cub_file)->map2d[y]);
		// 	y++;
		// }
		// break ;
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			// printf("1 len_of_c %f\n", cub_file->len_of_c);
			// cub_file->len_of_c = cub_file->Rx * -1;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -180)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			// cub_file->len_of_c = cub_file->Rx * -1;
			// printf("2 len_of_c %f\n", cub_file->len_of_c);
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
		{
			// printf("%c\n", cub_file->map2d[(int)cub_file->c_y][cub_file->c_x]);
			// printf("3 len_of_c %f\n", cub_file->len_of_c);
			while (--(cub_file->len_of_c) > 0)
			{
				cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cos(cub_file->FOV);
				cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sin(cub_file->FOV);
				my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
			}
			i = 0;
			break ;
		}
	}
	// 	// i = 0;
	// 	// cub_file->FOV += PI / 180;
	// 	cub_file->FOV += (PI / 3) / cub_file->Rx;
	// }

	// void	draw_map_2d(t_parse *cub_file, int x, int y) // ***OLDOLDOLDOLDOLDOLD***
	// {
	// 	while (cub_file->map2d[y][x])
	// 	{
	// 		while (cub_file->map2d[y][x])
	// 		{
	// 			if (cub_file->map2d[y][x] == '1' || cub_file->map2d[y][x] == '6'
	// 			|| cub_file->map2d[y][x] == '7' || cub_file->map2d[y][x] == '8' || cub_file->map2d[y][x] == '9')
	// 				my_mlx_pixel_put(cub_file, x, y, 0x074517); // dark green
	// 			// else if (cub_file->map2d[y][x] == 'N' || cub_file->map2d[y][x] == 'S'
	// 			// || cub_file->map2d[y][x] == 'E' || cub_file->map2d[y][x] == 'W')
	// 			// 	my_mlx_pixel_put(cub_file, x, y, 0x7a0505); // dark red // на карте больше нет этих букв, удали это
	// 			else if (cub_file->map2d[y][x] == '2')
	//    		        my_mlx_pixel_put(cub_file, x, y, 0x5c5a19); // dark yellow
	// 			else if (cub_file->map2d[y][x] == ' ')
	//    		        my_mlx_pixel_put(cub_file, x, y, 0x0e5859); // dark blue
	// 			x++;
	// 		}
	// 		x = 0;
	// 		y++;
	// 	}
	// 	// printf("FOV %f\n", cub_file->FOV);
	// 	cub_file->len_of_c = 0;   // бросание лучей на карте
	// 	cub_file->FOV = cub_file->player_a - (PI / 6);
	// 	while (cub_file->FOV <= cub_file->player_a + (PI / 6))
	// 	{
	// 		while (cub_file->len_of_c < cub_file->Ry + 100)
	// 		{
	// 			cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cos(cub_file->FOV);
	// 			cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sin(cub_file->FOV);
	// 			// my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0x3d082c);
	// 			my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
	// 			if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0'
	// 			&& cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != cub_file->p_of_view) // cub_file->p_of_view не надо. убери это
	// 			{
	// 				// printf("cub_file->c_x %d, cub_file->c_y %d\n", cub_file->c_x + 1, cub_file->c_y + 1);
	// 				// printf("1 cub_file->c_x / SCALE %d, cub_file->c_y / SCALE %d\n", (cub_file->c_x + 1) % SCALE, (cub_file->c_y + 1) % SCALE);
	// 				// printf("0 cub_file->c_x / SCALE %d, cub_file->c_y / SCALE %d\n\n", cub_file->c_x % SCALE, cub_file->c_y % SCALE); // wrong
	// 					break ;
	// 			}
	// 			cub_file->len_of_c += 1;
	// 		}
	// 		cub_file->len_of_c = 0;
	// 		cub_file->FOV += PI / 180;
	// 		cub_file->FOV += PI / 180 / 18;
	// 	}
	// 	// printf("player_a %f\n", cub_file->player_a);
	// 	// printf("%f\n", cub_file->player_a * 180 / PI);
}