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

  #include "cub3d.h"
 
int			get_coordinate_of_player(t_parse **cub_file) //ok
{
	char	**tmp;
	int		x;
	int		y;
	int 	tmp_y;

	tmp = (*cub_file)->map2d;
	x = 0;
	y = 0;
	while (tmp[y][x])
	{
		while(tmp[y][x])
		{
			if (tmp[y][x] == 'N' || tmp[y][x] == 'S' || tmp[y][x] == 'W' || tmp[y][x] == 'E')
			{
				(*cub_file)->player_x = x + SCALE / 2;
				(*cub_file)->player_y = y + SCALE / 2;
				(*cub_file)->p_of_view = tmp[y][x];
				while (tmp[y][x] == (*cub_file)->p_of_view)
					tmp[y][x++] = '0';
				tmp_y = y;
				while (y < tmp_y + SCALE - 1)
					ft_strcpy(tmp[++y], tmp[tmp_y]);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	

	return (0);
}

int			get_player_point_of_view(t_parse **cub_file) //ok
{
	if ((*cub_file)->p_of_view == 'N')
		(*cub_file)->player_a = 3 * PI / 2;
	else if ((*cub_file)->p_of_view == 'S')
		(*cub_file)->player_a = PI / 2;
	else if ((*cub_file)->p_of_view == 'W')
		(*cub_file)->player_a = PI;
	else
		(*cub_file)->player_a = 0;

	return (0);
}

int	move2d(t_parse **cub_file) // ok
{
	if (!(get_coordinate_of_player(cub_file)))
		return (-1);
	get_player_point_of_view(cub_file);
	printf("move_2d player_y %d\n", (*cub_file)->player_y);
	printf("move_2d player_x %d\n", (*cub_file)->player_x);

	return (0);
}

int					get_textures(t_parse **cub_file) // ok
{
	if (((*cub_file)->img_north = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->NO, &(*cub_file)->width_north, &(*cub_file)->height_north)) == NULL)
		ft_error("cant`t get the address of NORTH texture");
	if (((*cub_file)->img_south = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->SO, &((*cub_file)->width_south), &((*cub_file)->height_south))) == NULL)
		ft_error("cant`t get the address of SOUTH texture");
	if (((*cub_file)->img_west = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->WE, &(*cub_file)->width_west, &(*cub_file)->height_west)) == NULL)
		ft_error("cant`t get the address of WEST texture");
	if (((*cub_file)->img_east = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->EA, &(*cub_file)->width_east, &(*cub_file)->height_east)) == NULL)
		ft_error("cant`t get the address of EAST texture");
	if (((*cub_file)->img_sprite = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->S, &(*cub_file)->width_sprite, &(*cub_file)->height_sprite)) == NULL)
		ft_error("cant`t get the address of SPRITE texture");
	return (0);
}

void	draw_sky_and_floor(t_parse **cub_file, int x, int y) // ok
{
	int color_int;
	color_int = ((unsigned char)(*cub_file)->floor[0] << 16) + ((unsigned char)(*cub_file)->floor[1] << 8) + (unsigned char)(*cub_file)->floor[2];
	while (x < (*cub_file)->Rx) // draw sky
	{
		y = 0;
		while (y < (*cub_file)->Ry / 2)
		{
			my_mlx_pixel_put((*cub_file), x, y, color_int);
			y++;
		}
		x++;
	}

	x = 0;
	y = (*cub_file)->Ry / 2;
	color_int = ((unsigned char)(*cub_file)->ceilling[0] << 16) + ((unsigned char)(*cub_file)->ceilling[1] << 8) + (unsigned char)(*cub_file)->ceilling[2];
	while (x < (*cub_file)->Rx) // draw ground
	{
		y = (*cub_file)->Ry / 2;
		while (y < (*cub_file)->Ry)
		{
			my_mlx_pixel_put((*cub_file), x, y, color_int);
			y++;
		}
		x++;
	}
}

void	draw(t_parse **cub_file)
{
    (*cub_file)->img = mlx_new_image((*cub_file)->mlx, (*cub_file)->Rx, (*cub_file)->Ry);
    (*cub_file)->addr = mlx_get_data_addr((*cub_file)->img, &(*cub_file)->bits_per_pixel, &(*cub_file)->line_length, &(*cub_file)->endian);
	draw_sky_and_floor(cub_file, 0, 0);
	ray_cast(cub_file);
	// draw_map_2d(cub_file, 0, 0);
	// printf("player_a = %f, 0cub_file->FOV %f, 1cub_file->FOV %f\n\n", cub_file->player_a * 180 / PI, (cub_file->player_a - (PI / 6)) * 180 / PI, (cub_file->player_a + (PI / 6)) * 180 / PI);
    mlx_put_image_to_window((*cub_file)->mlx, (*cub_file)->win, (*cub_file)->img, 0, 0);
}

int             main(int argc, char **argv)
{
// start no lyb
    (void)argc;
    int         fd;
	static t_parse *cub_file;

    if (!(cub_file = create_new_elem()))
        return (-1);
    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return (-1); // напечатать ошибку
    if (parse(fd, &cub_file) < 0)
        return (-1); // напечатать соответствующу ошибку
	convert_map(&cub_file);
	move2d(&cub_file);
	close(fd);
	
	// int y=0;  //printf converted map (map2d[][])
	// while (y <= cub_file->map_y * SCALE)
	// {
	// 	printf("%s\n", cub_file->map2d[y]);
	// 	y++;
	// }

    cub_file->mlx = mlx_init();
    cub_file->win = mlx_new_window(cub_file->mlx, 1920, 1080, "Hello world!");
	get_textures(&cub_file);
	draw(&cub_file);
	mlx_hook(cub_file->win, 2, 1L<<0, key_hook, &cub_file);
    mlx_loop(cub_file->mlx);
	// free struct
// end no lyb

   
	return (0);
}

int             key_hook(int keycode, t_parse **cub_file)
{
	int *player_x = &(*cub_file)->player_x;
	int *player_y = &(*cub_file)->player_y;
	int	step;

	if (keycode == 13)
	{
		// printf("1 player_y = %d, player_x = %d, map2d[][] %c\n", *player_y, *player_x, (*cub_file)->map2d[*player_y][*player_x]);
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		if ((*cub_file)->player_y > 0 && (*cub_file)->map2d
		[*player_y + (int)(1 * sinl((*cub_file)->player_a))][*player_x + (int)(1 * cosl((*cub_file)->player_a))] == '0')
		{
			step = 1;
			while ((*cub_file)->map2d[*player_y + (int)(step * sinl((*cub_file)->player_a))][*player_x + (int)(step * cosl((*cub_file)->player_a))] == '0'
			&& step <= 20)
				step++;
		 	*player_y = *player_y + (int)(--step * sinl((*cub_file)->player_a));
		 	*player_x = *player_x + (int)(step * cosl((*cub_file)->player_a));
		}
		draw(cub_file);
	}
	if (keycode == 0)
	{
    	// printf("You have pressed the key 'A'!\n");
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		if ((*cub_file)->player_y > 0 && (*cub_file)->map2d
		[*player_y - (int)(1 * cosl((*cub_file)->player_a))][*player_x + (int)(1 * sinl((*cub_file)->player_a))] == '0')
		{
			step = 1;
			while ((*cub_file)->map2d[*player_y - (int)(step * cosl((*cub_file)->player_a))][*player_x + (int)(step * sinl((*cub_file)->player_a))] == '0'
			&& step <= 20)
				step++;
			(*cub_file)->map2d[*player_y][*player_x] = '0';
		 	*player_y = *player_y - (int)(--step * cosl((*cub_file)->player_a));
		 	*player_x = *player_x + (int)(step * sinl((*cub_file)->player_a));
			//  printf("player_y = %d, player_x = %d, map2d[][] %c\n", *player_y, *player_x, (*cub_file)->map2d[*player_y][*player_x]);
		}
		draw(cub_file);
	}
	if (keycode == 1)
	{
    	// printf("You have pressed the key 'S'!\n");
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		if ((*cub_file)->player_y > 0 && (*cub_file)->map2d
		[*player_y - (int)(1 * sinl((*cub_file)->player_a))][*player_x - (int)(1 * cosl((*cub_file)->player_a))] == '0')
		{
			step = 1;
			while ((*cub_file)->map2d[*player_y - (int)(step * sinl((*cub_file)->player_a))][*player_x - (int)(step * cosl((*cub_file)->player_a))] == '0'
			&& step <= 20)
				step++;
			(*cub_file)->map2d[*player_y][*player_x] = '0';
		 	*player_y = *player_y - (int)(--step * sinl((*cub_file)->player_a));
		 	*player_x = *player_x - (int)(step * cosl((*cub_file)->player_a));
			//  printf("player_y = %d, player_x = %d, map2d[][] %c\n", *player_y, *player_x, (*cub_file)->map2d[*player_y][*player_x]);
		}
		draw(cub_file);
	}
	if (keycode == 2)
	{
    	// printf("You have pressed the key 'D'!\n");
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		if ((*cub_file)->player_y > 0 && (*cub_file)->map2d
		[*player_y + (int)(1 * cosl((*cub_file)->player_a))][*player_x - (int)(1 * sinl((*cub_file)->player_a))] == '0')
		{
			step = 1;
			while ((*cub_file)->map2d[*player_y + (int)(step * cosl((*cub_file)->player_a))][*player_x - (int)(step * sinl((*cub_file)->player_a))] == '0'
			&& step <= 20)
				step++;
			(*cub_file)->map2d[*player_y][*player_x] = '0';
		 	*player_y = *player_y + (int)(--step * cosl((*cub_file)->player_a));
		 	*player_x = *player_x - (int)(step * sinl((*cub_file)->player_a));
			//  printf("player_y = %d, player_x = %d, map2d[][] %c\n", *player_y, *player_x, (*cub_file)->map2d[*player_y][*player_x]);
		}
		draw(cub_file);	
	}
	if (keycode == 123)
	{
    	// printf("You have pressed the key '<'!\n");
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		(*cub_file)->player_a -= 5 * PI/180;
		// (*cub_file)->player_a -= (PI / 3) / (*cub_file)->Rx * 5;
		draw(cub_file);

	}
	if (keycode == 124)
	{
    	// printf("You have pressed the key '>'!\n");
		mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
		(*cub_file)->player_a += 5 * PI/180; // 10 градусов
		// (*cub_file)->player_a += (PI / 3) / (*cub_file)->Rx * 5;
		draw(cub_file);

	}
	if (keycode == 53)
	{
    	// printf("You have pressed the key 'ESC'!\n");
		mlx_destroy_window((*cub_file)->mlx, (*cub_file)->win);
		exit(1);
	}
	//  else
    //  	printf("Hello from key_hook!\n");
	return (0);
}