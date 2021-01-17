/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2020/12/29 17:06: 6by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../get_next_line/get_next_line.h"

t_parse *create_new_elem(void)
{
    t_parse *new_elem;
    if (!(new_elem = (t_parse *)malloc(sizeof(t_parse))))
	    return (NULL);
    new_elem->p_file = NULL;
    new_elem->Rx = -1;
    new_elem->Ry = -1;
    new_elem->NO = NULL;
    new_elem->SO = NULL;
    new_elem->WE = NULL;
    new_elem->EA = NULL;
    new_elem->S = NULL;
    new_elem->Fr = -1;
    new_elem->Fg = -1;
    new_elem->Fb = -1;
    new_elem->Cr = -1;
    new_elem->Cg = -1;
    new_elem->Cb = -1;
    new_elem->map = NULL;
    new_elem->map_x = 0;
    new_elem->map_y = 0;
	(new_elem)->map2d = NULL;
    new_elem->player_x = -1;
    new_elem->player_y = -1;
    return (new_elem);
}

int parse(int fd, t_parse *cub_file)
{
    char        *line;
    char        *tmp;

    while((get_next_line(fd, &line)))
    {
        tmp = cub_file->p_file;
        cub_file->p_file = ft_strjoin(cub_file->p_file, line);
        if (tmp != NULL)
            free(tmp);
        tmp = cub_file->p_file;
        cub_file->p_file = ft_strjoin(cub_file->p_file, "\n");
        free(tmp);
        free(line);
    }
    tmp = cub_file->p_file;
		cub_file->p_file = ft_strjoin(cub_file->p_file, line);
	if (tmp != NULL)
		free(tmp);
	tmp = cub_file->p_file;
	cub_file->p_file = ft_strjoin(cub_file->p_file, "\n");
    free(tmp);
	free(line);
	if (parse2(&cub_file, 0) == -1)
		return (-1);
	if (check_if_parsed_file_is_ok(&cub_file) == -1)
		return (-1);
    return (0);
}

int	parse2(t_parse **cub_file, int i)
{
	char *tmp;
	
	tmp = (*cub_file)->p_file;
	while (tmp[i] == '\n')
		i++;
	if ((!tmp[i]) && (!(tmp[i + 1])))
		return (-1);
	if (tmp[i] == 'R')
		i = get_resolution(cub_file, i);
	else if (tmp[i] == 'N')
		i = get_north_texture(cub_file, i);
	else if (tmp[i] == 'S' && tmp[i + 1] == 'O')
		i = get_south_texture(cub_file, i);
	else if (tmp[i] == 'W')
		i = get_west_texture(cub_file, i);
	else if (tmp[i] == 'E')
		i = get_east_texture(cub_file, i);
	else if (tmp[i] == 'S')
		i = get_sprite_texture(cub_file, i);
	else if (tmp[i] == 'F')
		i = get_floor_color(cub_file, i);
	else if (tmp[i] == 'C')
		i = get_ceiling_color(cub_file, i);
	else if (tmp[i] == ' ' || tmp[i] == '0' || tmp[i] == '1')
		i = get_map(cub_file, i);
	else
		return (-1); // configuratiob file error
	return (i);
}

int	get_map(t_parse **cub_file, int i)
{
	char	*tmp;
	int		players;
	int		tmp_x;

	if ((*cub_file)->map != NULL)
		return (-1); // configuration file error
	if (!((*cub_file)->map = ft_strdup((*cub_file)->p_file + i)))
		return (-1);
	tmp = (*cub_file)->p_file;
	tmp_x = 0;
	players = 0;
	while (tmp[i])
	{
		if ((*cub_file)->map_x < tmp_x)
			(*cub_file)->map_x = tmp_x;
		if (tmp[i] == ' ' || tmp[i] == '0' || tmp[i] == '1' || tmp[i] == '2')
			tmp_x++;
		else if (tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E')
		{
			tmp_x++;
			players++;
		}
		else if ((tmp[i] == '\n' && tmp[i + 1] != '\n'))
		{
			tmp_x = 0;
			(*cub_file)->map_y++;
		}
		else if (tmp[i] == '\n')
			i++;
		else
		{
			printf("map is not the last argument");
			return (-1);
		}
		i++;
	}
	if (players != 1)
	{
		if (players < 1)
			printf("there is no player in the map\n");
		if (players > 1)
			printf("there is too many players in the map\n");
		return (-1); // too many players
	}
	 
    printf("map\n%s\n", (*cub_file)->map);
    printf("начиная с 1 map_x %d\n", (*cub_file)->map_x);
    printf("начиная с 1 map_y %d\n", (*cub_file)->map_y);
	if (convert_map(cub_file) == -1)
		return (-1);
	return (i);
}
int					convert_map(t_parse **cub_file)
{
	int 	x;
	int		y;
	int 	i;

	x = 0;
	y = 0;
	i = 0;
	int a = 1;
	int b = 1;
	if ((check_if_map_is_last(cub_file)) == -1)
		return (-1); // config file error

	// if (!((*cub_file)->map2d[y] = (char *)malloc(sizeof(char) * ((*cub_file)->map_x * SCALE + 1))))
	if (!((*cub_file)->map2d = (char **)malloc(sizeof(char *) * (((*cub_file)->map_y * SCALE) + 1))))
		return (-1); // malloc error

	while (y < (*cub_file)->map_y * SCALE) // (наверное здесь (map_y - 1) * SCALE, потому что map_y ведет отсчет от 1)
	{
		if (!((*cub_file)->map2d[y] = (char *)malloc(sizeof(char) * ((*cub_file)->map_x * SCALE + 1))))
			return (-1);
		while (x < (*cub_file)->map_x * SCALE)
		{
			while (x < (*cub_file)->map_x * SCALE && x < SCALE * a)
			{
				(*cub_file)->map2d[y][x++] = (*cub_file)->map[i];
			}
			if ((*cub_file)->map[i + 1] == '\n' || (*cub_file)->map[i + 1] == '\0')
			{
				while (x < (*cub_file)->map_x * SCALE)
				{
					(*cub_file)->map2d[y][x++] = ' ';
				}
				(*cub_file)->map2d[y][x] = '\0';
				i++;
			}
			a++;
			i++;
		}
		while (++y < SCALE * b)
		{
			(*cub_file)->map2d[y] = ft_strdup((*cub_file)->map2d[y - 1]);
		}
		a = 1;
		b++;
		x = 0;
	}
	x = 0;
	if (!((*cub_file)->map2d[y] = (char *)malloc(sizeof(char) * ((*cub_file)->map_x * SCALE + 1))))
		return (-1);
	while (x <= (*cub_file)->map_x * SCALE)
		(*cub_file)->map2d[y][x++] = '\0';
	
	// printf("\nconverted_map\n");
	// // while ((*cub_file)->map2d[y][0])
	// y = 0;
	// x = 0;
	// while ((*cub_file)->map2d[y][x])
	// {
	// 	printf("%s\n", (*cub_file)->map2d[y]);
	// 	y++;
	// }
	// // printf("y %d, x %d\n", y, x);
    // printf("map_x %d\n", (*cub_file)->map_x);
    // printf("map_y %d\n", (*cub_file)->map_y);

	// convert_map_NWSE(cub_file);
	if (get_coordinate_of_spites(*cub_file) == -1)
		return (-1);
	return (0);
}

int					get_coordinate_of_spites(t_parse *cub_file)
{
	int y = 0;
	int x = 0;
	int	i = 0;

	cub_file->num_of_sprites = count_sprites(cub_file->map);
	if (!(cub_file->sprites = (int **)malloc(sizeof(int *) * cub_file->num_of_sprites)))
		return (-1); // print malloc error
	while (y < cub_file->map_y * SCALE && i < cub_file->num_of_sprites)
	{
		while (x < cub_file->map_x * SCALE)
		{
			if (cub_file->map2d[y][x] == '2')
			{
				if (!(cub_file->sprites[i] = (int *)malloc(sizeof(int) * 3)))
					return (-1); // print malloc error
				cub_file->sprites[i][0] = y / SCALE; // y
				cub_file->sprites[i][1] = x / SCALE; // x
				cub_file->sprites[i][2] = 0; // drawn (1) or not drawn (0)
				i++;
			}
			x += SCALE;
		}
		x = 0;
		y += SCALE;
		printf("y %d. x %d, i %d\n", y, x, i);
		printf("map_y x SCALE %d\n", cub_file->map_y * SCALE);
	}

	i = 0; // printf
	while (i < cub_file->num_of_sprites)
	{
		printf("[i][0] = %d, [i][1] = %d, [i][2] = %d\n", cub_file->sprites[i][0], cub_file->sprites[i][1], cub_file->sprites[i][2]);
		i++;
	}
	printf("--------\n\n");

	return (0);
}

int 		count_sprites(char *map)
{
	int i = 0;
	int num_of_sprites = 0;

	while (map[i])
	{
		if (map[i] == '2')
			num_of_sprites++;
		i++;
	}
	return (num_of_sprites);
}
void					convert_map_NWSE(t_parse **cub_file)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while ((*cub_file)->map2d[y][x]) // запад и восток
	{
		while ((*cub_file)->map2d[y][x]) // 6 - север, 7 - юг, 8 - запад, 9 - восток
		{
			if (x % SCALE == 0)
				if ((*cub_file)->map2d[y][x] == '1' || (*cub_file)->map2d[y][x] == '6' || (*cub_file)->map2d[y][x] == '7')
					(*cub_file)->map2d[y][x] = '9';
			if ((x - 1) % SCALE != 0 && x > 0)
				if ((*cub_file)->map2d[y][x - 1] == '1' || (*cub_file)->map2d[y][x - 1] == '6' || (*cub_file)->map2d[y][x - 1] == '7')
					(*cub_file)->map2d[y][x - 1] = '8';
			y++;
		}
		y = 0;
		x = SCALE * ++i;
		if (x >= (*cub_file)->map_x * SCALE)
			break ;
	}
	x = 0;
	y = 0;
	while (y < (*cub_file)->map_y * SCALE)
	{
		while (x < (*cub_file)->map_x * SCALE - 2)
		{
			if ((*cub_file)->map2d[y][x] == '8' && (*cub_file)->map2d[y][x + 1] == '9' && (*cub_file)->map2d[y][x + 2] == '1')
			{
				(*cub_file)->map2d[y][x] = '1';
				(*cub_file)->map2d[y][x + 1] = '1';
			}
			x++;
		}
		x = 0;
		y++;
	}
	// x = 0;
	// y = 0;
	// while (y < (*cub_file)->map_y * SCALE)
	// {
	// 	while (x < (*cub_file)->map_x * SCALE - 2)
	// 	{
	// 		if ((*cub_file)->map2d[y][x] == '0' && (*cub_file)->map2d[y][x + 1] == '9' && (*cub_file)->map2d[y][x + 2] == '1')
	// 		{
	// 			while ((*cub_file)->map2d[y][x + 2])
	// 			{
	// 				if ((*cub_file)->map2d[y][x + 2] == '1')
	// 					(*cub_file)->map2d[y][x++ + 2] = '9';
	// 			}
	// 		}
	// 		if ((*cub_file)->map2d[y][x] == '9' && (*cub_file)->map2d[y][x + 1] == '1' && (*cub_file)->map2d[y][x + 2] == '1')
	// 			(*cub_file)->map2d[y][x] = '1';
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	// printf("zdes\n");
	// x = 0;
	// y = 0;
	// while (y < (*cub_file)->map_y * SCALE)
	// {
	// 	while (x < (*cub_file)->map_x * SCALE)
	// 	{
	// 		if (x >= 3)
	// 		{
	// 			if ((*cub_file)->map2d[y][x] == '0' && (*cub_file)->map2d[y][x - 1] == '8' && (*cub_file)->map2d[y][x - 2] == '1')
	// 			{
	// 				while (x - 2 >= 0 && (*cub_file)->map2d[y][x - 2] != '0' && (*cub_file)->map2d[y][x - 2] != '2')
	// 				{
	// 					if ((*cub_file)->map2d[y][x - 2] == '1')
	// 					(*cub_file)->map2d[y][x-- - 2] = '8';
	// 				}
	// 			}
	// 		}
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }

	// printf("\n87converted_map NWSE\n");
	// y = 0;
	// while (y <= (*cub_file)->map_y * SCALE)
	// {
	// 	printf("%s\n", (*cub_file)->map2d[y]);
	// 	y++;
	// }
}