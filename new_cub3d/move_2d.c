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
 
void		get_coordinate_of_player(t_parse **cub_file) //ok
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
				(*cub_file)->player_x = x + (*cub_file)->scale / 2;
				(*cub_file)->player_y = y + (*cub_file)->scale / 2;
				(*cub_file)->p_of_view = tmp[y][x];
				while (tmp[y][x] == (*cub_file)->p_of_view)
					tmp[y][x++] = '0';
				tmp_y = y;
				while (y < tmp_y + (*cub_file)->scale - 1)
					ft_strcpy(tmp[++y], tmp[tmp_y]);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		get_player_point_of_view(t_parse **cub_file) //ok
{
	if ((*cub_file)->p_of_view == 'N')
		(*cub_file)->player_a = 3 * PI / 2;
	else if ((*cub_file)->p_of_view == 'S')
		(*cub_file)->player_a = PI / 2;
	else if ((*cub_file)->p_of_view == 'W')
		(*cub_file)->player_a = PI;
	else
		(*cub_file)->player_a = 0;
}

int	move2d(t_parse **cub_file) // ok
{
	get_coordinate_of_player(cub_file);
	get_player_point_of_view(cub_file);
	printf("move_2d player_y %d\n", (*cub_file)->player_y);
	printf("move_2d player_x %d\n", (*cub_file)->player_x);

	return (0);
}

int					get_textures(t_parse **cub_file) // ok
{
	if (((*cub_file)->img_north = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->NO, &(*cub_file)->width_north, &(*cub_file)->height_north)) == NULL)
		ft_error("cant`t get the address of NORTH texture (path to texture is wrong)");
	if (((*cub_file)->img_south = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->SO, &((*cub_file)->width_south), &((*cub_file)->height_south))) == NULL)
		ft_error("cant`t get the address of SOUTH texture (path to texture is wrong)");
	if (((*cub_file)->img_west = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->WE, &(*cub_file)->width_west, &(*cub_file)->height_west)) == NULL)
		ft_error("cant`t get the address of WEST texture (path to texture is wrong)");
	if (((*cub_file)->img_east = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->EA, &(*cub_file)->width_east, &(*cub_file)->height_east)) == NULL)
		ft_error("cant`t get the address of EAST texture (path to texture is wrong)");
	if (((*cub_file)->img_sprite = mlx_xpm_file_to_image((*cub_file)->mlx, (*cub_file)->S, &(*cub_file)->width_sprite, &(*cub_file)->height_sprite)) == NULL)
		ft_error("cant`t get the address of SPRITE texture (path to texture is wrong)");
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

void	draw(t_parse **cub_file, int argc)
{
    if (((*cub_file)->img = mlx_new_image((*cub_file)->mlx, (*cub_file)->Rx, (*cub_file)->Ry)) == (void *)0)
		ft_error("cannot do mlx_new_image");
    (*cub_file)->addr = mlx_get_data_addr((*cub_file)->img, &(*cub_file)->bits_per_pixel, &(*cub_file)->line_length, &(*cub_file)->endian);
	draw_sky_and_floor(cub_file, 0, 0);
	ray_cast(cub_file);
	if (argc == 2)
		mlx_put_image_to_window((*cub_file)->mlx, (*cub_file)->win, (*cub_file)->img, 0, 0);
}

int             main(int argc, char **argv)
{
	static t_parse *cub_file;
	
	if (argc == 1)
		ft_error("the map is not given. Write in the command line \"cub3D example.cub\"");
	else if (argc > 3)
		ft_error("cub3D works no more than 1 argument: \"--save\"");

    if (!(cub_file = create_new_elem()))
        return (-1);
	work_with_cub_file(&cub_file, argc, argv);
	mlx_hook(cub_file->win, 2, 1L<<0, key_hook, &cub_file);
	mlx_hook(cub_file->win, 17, 1L<<0, red_cross, &cub_file);
    mlx_loop(cub_file->mlx);
	return (0);
}

void			work_with_cub_file(t_parse **cub_file, int argc, char **argv)
{
	int fd;

	check_if_dot_cub(argv[1]);
    if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("cannot open the given *.cub file");
    parse(fd, cub_file);
	ft_define_scale(cub_file);
	convert_map(cub_file);
	get_coordinate_of_player(cub_file);
	get_player_point_of_view(cub_file);
	close(fd);
    if (((*cub_file)->mlx = mlx_init()) == (void *)0)
		ft_error("cannot do mlx_init");
	get_textures(cub_file);
	if (argc == 2)
   		(*cub_file)->win = mlx_new_window((*cub_file)->mlx, (*cub_file)->Rx, (*cub_file)->Ry, "cub3D");
	draw(cub_file, argc);
	if (argc == 3)
		ft_screenshot(cub_file, argv[2]);
}

void				check_if_dot_cub(char *filename)
{
	int len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u' || filename[len - 3] != 'c' || filename[len - 4] != '.')
		ft_error("configuration file should have .cub extension - example.cub");
}

void			ft_define_scale(t_parse **cub_file)
{
	if ((*cub_file)->Rx <= 30)
		(*cub_file)->scale = 25;
	else if ((*cub_file)->Rx <= 50)
		(*cub_file)->scale = 20;
	else if ((*cub_file)->Rx <= 100)
		(*cub_file)->scale = 30;
	else if ((*cub_file)->Rx <= 200)
		(*cub_file)->scale = 50;
	else if ((*cub_file)->Rx <= 300)
		(*cub_file)->scale = 85;
	else
		(*cub_file)->scale = 100;
}

int             key_hook(int keycode, t_parse **cub_file)
{
	int *player_x = &(*cub_file)->player_x;
	int *player_y = &(*cub_file)->player_y;
	int	step;

	// int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
	mlx_destroy_image((*cub_file)->mlx, (*cub_file)->img);
	mlx_clear_window((*cub_file)->mlx, (*cub_file)->win);
	if (keycode == 13)
	{
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
	}
	if (keycode == 0)
	{
    	// printf("You have pressed the key 'A'!\n");
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
		}
	}
	if (keycode == 1)
	{
    	// printf("You have pressed the key 'S'!\n");
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
		}
	}
	if (keycode == 2)
	{
    	// printf("You have pressed the key 'D'!\n");
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
		}
	}
	if (keycode == 123)
	{
    	// printf("You have pressed the key '<'!\n");
		(*cub_file)->player_a -= 5 * PI/180;

	}
	if (keycode == 124)
	{
    	// printf("You have pressed the key '>'!\n");
		(*cub_file)->player_a += 5 * PI/180; // 10 градусов

	}
	if (keycode == 53)
	{
		mlx_destroy_window((*cub_file)->mlx, (*cub_file)->win);
		exit(0);
	}
	draw(cub_file, 2);


	return (0);
}

int             red_cross(t_parse **cub_file)
{
	mlx_destroy_window((*cub_file)->mlx, (*cub_file)->win);
	exit(0);
	return (0);
}