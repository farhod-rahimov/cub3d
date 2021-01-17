/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:38:29 by btammara          #+#    #+#             */
/*   Updated: 2021/01/14 11:22:14 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
#include "../cub3d.h"

long double check_upper_side_walls(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1) // UPPER
	{
		cub_file->len_of_c = ((SCALE * i++ + ((cub_file->player_y % SCALE) + 1)) / sinl(cub_file->FOV));
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		// cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
		// cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// cub_file->map2d[cub_file->player_y][cub_file->player_x] = 'N';
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
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			// printf("1 len_of_c %f\n", cub_file->len_of_c);
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			// printf("2 len_of_c %f\n", cub_file->len_of_c);
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '2')
		{
			// printf("%c\n", cub_file->map2d[(int)cub_file->c_y][cub_file->c_x]);
			// printf("3 len_of_c %f\n", cub_file->len_of_c);
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '0')
			// {
			// 	cub_file->len_of_c -= 0.01;
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// }
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
			// {
			// 	cub_file->len_of_c += 0.01;
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
			// }
			// while (++(cub_file->len_of_c) < 0)
			// {
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// 	my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
			// }
			// i = 0;
			break ;
		}
	}
	return (cub_file->len_of_c);
}

long double check_lower_side_walls(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1) // LOWER
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_y % SCALE))) / sinl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		// cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
		// cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
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
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -180)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 180) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			// printf("2 len_of_c %f\n", cub_file->len_of_c);
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '2')
		{
			// printf("%c\n", cub_file->map2d[(int)cub_file->c_y][cub_file->c_x]);
			// printf("3 len_of_c %f\n", cub_file->len_of_c);
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '0')
			// {
			// 	cub_file->len_of_c += 0.01;
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
			// }
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
			// {
			// 	cub_file->len_of_c -= 0.01;
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
			// }
			// while (--(cub_file->len_of_c) > 0)
			// {
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
			// 	my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
			// }
			// i = 0;
			break ;
		}
	}
	return (cub_file->len_of_c);
}

long double check_left_side_walls(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1) // LEFT
	{
		cub_file->len_of_c = (SCALE * i++ + ((cub_file->player_x % SCALE) + 1)) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		// cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
		// cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// cub_file->map2d[cub_file->player_y][cub_file->player_x] = 'N';
			// cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] = 'K';
			// y = 0;
			// while (y <= (cub_file)->map_y * SCALE)
			// {
			// 	printf("%s\n", (cub_file)->map2d[y]);
			// 	y++;
			// }
			// break ;
		// printf("len_of_c %f, c_x %f, c_y %f, FOV %f\n", cub_file->len_of_c, cub_file->c_x, cub_file->c_y, cub_file->FOV * 180 / PI);
		// printf("len_of_c %f, c_x %d, c_y %f, FOV %f\n", cub_file->len_of_c, cub_file->c_x, cub_file->c_y, cub_file->FOV * 180 / PI);
		// cub_file->map2d[cub_file->player_y][cub_file->player_x] = 'N';
		// cub_file->map2d[(int)cub_file->c_y][cub_file->c_x] = 'K';
		// y = 0;
		// while (y <= (cub_file)->map_y * SCALE)
		// {
		// 	printf("%s\n", (cub_file)->map2d[y]);
		// 	y++;
		// }
		if (cub_file->c_x > cub_file->map_x * SCALE || cub_file->c_y > cub_file->map_y * SCALE ||
		cub_file->c_x < 0 || cub_file->c_y < 0)
		{
			// printf("1 len_of_c %f\n", cub_file->len_of_c);
			cub_file->len_of_c = cub_file->Rx * -10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) >= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) > -360)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) <= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= 0)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 270) && (int)((int)(cub_file->FOV * 180 / PI) % 360) < 360))
		{
			cub_file->len_of_c = cub_file->Rx * -10;
			// printf("2 len_of_c %f\n", cub_file->len_of_c);
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '2')
		{
			// printf("%c\n", cub_file->map2d[(int)cub_file->c_y][cub_file->c_x]);
			// printf("3 len_of_c %f\n", cub_file->len_of_c);
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '0')
			// {
			// 	cub_file->len_of_c -= 0.01;
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// }
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
			// {
			// 	cub_file->len_of_c += 0.01;
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
			// }
			// while (++(cub_file->len_of_c) < 0)
			// {
			// 	cub_file->c_x = cub_file->player_x - cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y - cub_file->len_of_c * sinl(cub_file->FOV);
			// 	my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
			// }
			// i = 0;
			break ;
		}
	}
	return (cub_file->len_of_c);
}

long double check_right_side_walls(t_parse *cub_file, int i)
{
	cub_file->len_of_c = 0;
	while (1) // RIGHT
	{
		cub_file->len_of_c = (SCALE * i++ + (SCALE - (cub_file->player_x % SCALE))) / cosl(cub_file->FOV);
		cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
		cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
		// cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
		// cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
			// cub_file->map2d[cub_file->player_y][cub_file->player_x] = 'N';
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
			cub_file->len_of_c = cub_file->Rx * 10;
			break ;
		}
		if ((((int)((int)(cub_file->FOV * 180 / PI) % 360) <= -90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) >= -270)
		|| (((int)((int)(cub_file->FOV * 180 / PI) % 360) >= 90) && (int)((int)(cub_file->FOV * 180 / PI) % 360) <= 270))
		{
			cub_file->len_of_c = cub_file->Rx * 10;
			// printf("2 len_of_c %f\n", cub_file->len_of_c);
			break ;
		}
		if (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0' && cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '2')
		{
			// printf("%c\n", cub_file->map2d[(int)cub_file->c_y][cub_file->c_x]);
			// printf("3 len_of_c %f\n", cub_file->len_of_c);
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] == '0')
			// {
			// 	cub_file->len_of_c += 0.01;
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
			// }
			// while (cub_file->map2d[(int)cub_file->c_y][(int)cub_file->c_x] != '0')
			// {
			// 	cub_file->len_of_c -= 0.01;
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV) + 0.1;
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV) + 0.1;
			// }
			// while (--(cub_file->len_of_c) > 0)
			// {
			// 	cub_file->c_x = cub_file->player_x + cub_file->len_of_c * cosl(cub_file->FOV);
			// 	cub_file->c_y = cub_file->player_y + cub_file->len_of_c * sinl(cub_file->FOV);
			// 	my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0xffffff);
			// }
			// i = 0;
			break ;
		}
	}
	return (cub_file->len_of_c);
}