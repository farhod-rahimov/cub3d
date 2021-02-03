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

t_parse *create_new_elem(void)// ok
{
    t_parse *new_elem;
    if (!(new_elem = (t_parse *)malloc(sizeof(t_parse))))
	    return (NULL);
    new_elem->p_file = NULL; // это надоо
    new_elem->Rx = -1;
    new_elem->Ry = -1;
    new_elem->NO = NULL; // это надоо
    new_elem->SO = NULL; // это надоо
    new_elem->WE = NULL; // это надоо
    new_elem->EA = NULL; // это надоо
    new_elem->S = NULL; // это надоо
    new_elem->floor[0] = -1;
    new_elem->floor[1] = -1;
    new_elem->floor[2] = -1;
    new_elem->ceilling[0] = -1;
    new_elem->ceilling[1] = -1;
    new_elem->ceilling[2] = -1;
    new_elem->map = NULL; // это надоо
    new_elem->map_x = 0; // это надоо
    new_elem->map_y = 0; // это надоо
    return (new_elem);
}

void	 parse(int fd, t_parse **cub_file)
{
    char        *line;
    char        *tmp;

    while((get_next_line(fd, &line)))
    {
        tmp = (*cub_file)->p_file;
        (*cub_file)->p_file = ft_strjoin_3((*cub_file)->p_file, line, "\n");
		if (tmp != NULL)
        	free(tmp);
        free(line);
    }

    tmp = (*cub_file)->p_file;
	(*cub_file)->p_file = ft_strjoin_3((*cub_file)->p_file, line, "\n");
	if (tmp != NULL)
		free(tmp);
	free(line);
	
	if (parse2(cub_file, 0) == -1)
		return ;
}

int	parse2(t_parse **cub_file, int i) // ok
{
	char *tmp;
	
	tmp = (*cub_file)->p_file;
	while (tmp[i] == '\n')
		i++;
	// if ((!tmp[i]) && (!(tmp[i + 1])))
	// 	return (-1);
	if (tmp[i] == 'R')
		i = get_resolution(cub_file, i);  // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'N')
		i = get_north_texture(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'S' && tmp[i + 1] == 'O')
		i = get_south_texture(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'W')
		i = get_west_texture(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'E')
		i = get_east_texture(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'S')
		i = get_sprite_texture(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'F')
		i = get_floor_color(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == 'C')
		i = get_ceiling_color(cub_file, i); // ok i в  ф-ии останавливается на \n 
	else if (tmp[i] == ' ' || tmp[i] == '0' || tmp[i] == '1')
		i = get_map(cub_file, i);
	else
		ft_error("*.cub file is not valid. It should have only 9 types of information: R, NO, SO, WE, EA, S, F, C and map");
	return (i);
}

int	get_map(t_parse **cub_file, int i) // ok
{
	char	*tmp;
	int		players;
	int		tmp_x;

	if ((*cub_file)->map != NULL)
		ft_error(".cub file has more than 1 map");
	if (!((*cub_file)->map = ft_strdup((*cub_file)->p_file + i)))
		ft_error("cannot allocate memmory for copying a map");
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
			if (++players > 1)
				ft_error("there are too many players in the map");
		}
		else if ((tmp[i] == '\n' && tmp[i + 1] != '\n'))
		{
			tmp_x = 0;
			(*cub_file)->map_y++;
		}
		else if (tmp[i] == '\n')
		{
			;
		}
		else
		{
			ft_error("*.cub file has errors. MAP should be placed in the end of *.cub file and it can have only 8 type of characters: 0(zero), 1, 2, ' '(space), N, S, W, E.");
			return (-1);
		}
		i++;
	}
	if (players == 0)
		ft_error("there is no player in the map");
	 
    printf("map\n%s\n", (*cub_file)->map);
    printf("начиная с 1 map_x %d\n", (*cub_file)->map_x);
    printf("начиная с 1 map_y %d\n", (*cub_file)->map_y);
	return (i);
}
int					convert_map(t_parse **cub_file) // ok
{
	int 	x;
	int		y;
	int 	i;

	x = 0;
	y = 0;
	i = 0;
	int a = 1;
	int b = 1;
	check_if_map_is_last(cub_file);

	if (!((*cub_file)->map2d = (char **)malloc(sizeof(char *) * (((*cub_file)->map_y * (*cub_file)->scale) + 1))))
		ft_error("cannot allocate memmory for converting map into 2-dimensional char array");

	while (y < (*cub_file)->map_y * (*cub_file)->scale)
	{
		if (!((*cub_file)->map2d[y] = (char *)malloc(sizeof(char) * ((*cub_file)->map_x * (*cub_file)->scale + 1))))
			ft_error("cannot allocate memmory for converting map into 2-dimensional char array");
		while (x < (*cub_file)->map_x * (*cub_file)->scale)
		{
			while (x < (*cub_file)->map_x * (*cub_file)->scale && x < (*cub_file)->scale * a)
			{
				(*cub_file)->map2d[y][x++] = (*cub_file)->map[i];
			}
			if ((*cub_file)->map[i + 1] == '\n' || (*cub_file)->map[i + 1] == '\0')
			{
				while (x < (*cub_file)->map_x * (*cub_file)->scale)
				{
					(*cub_file)->map2d[y][x++] = ' ';
				}
				(*cub_file)->map2d[y][x] = '\0';
				i++;
			}
			a++;
			i++;
		}
		while (++y < (*cub_file)->scale * b)
		{
			(*cub_file)->map2d[y] = ft_strdup((*cub_file)->map2d[y - 1]);
		}
		a = 1;
		b++;
		x = 0;
	}
	x = 0;
	if (!((*cub_file)->map2d[y] = (char *)malloc(sizeof(char) * ((*cub_file)->map_x * (*cub_file)->scale + 1))))
		ft_error("cannot allocate memmory for converting map into 2-dimensional char array");
	while (x <= (*cub_file)->map_x * (*cub_file)->scale)
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

	check_if_map_is_ok(cub_file);
	if (get_coordinate_of_spites(cub_file) == -1)
		return (-1);
	return (0);
}


int					get_coordinate_of_spites(t_parse **cub_file) //ok
{
	long double y = 0;
	long double  x = 0;
	int	i = 0;

	(*cub_file)->num_of_sprites = count_sprites((*cub_file)->map);
	if (!((*cub_file)->sprites = (long double **)malloc(sizeof(long double *) * (*cub_file)->num_of_sprites)))
		ft_error("cannot allocate memmory for **sprites");
	while (y < (*cub_file)->map_y * (*cub_file)->scale && i < (*cub_file)->num_of_sprites)
	{
		while (x < (*cub_file)->map_x * (*cub_file)->scale)
		{
			if ((*cub_file)->map2d[(int)y][(int)x] == '2')
			{
				if (!((*cub_file)->sprites[i] = (long double *)malloc(sizeof(long double) * 8)))
					ft_error("cannot allocate memmory for **sprites");
				(*cub_file)->sprites[i][0] = -1.0; // (*cub_file)->scale_sprite_x // каждый раз меняется
				(*cub_file)->sprites[i][1] = -1.0; // len_of_c (высота спрайта по его центру) // каждый раз меняется
				(*cub_file)->sprites[i][2] = y / (long double)(*cub_file)->scale; // координата y (y / (*cub_file)->scale) // после каждой отрисовки занчение НЕ меняем
				(*cub_file)->sprites[i][3] = x / (long double)(*cub_file)->scale; // координата x (x / (*cub_file)->scale) // после каждой отрисовки занчение НЕ меняем
				(*cub_file)->sprites[i][4] = -1; /// начало спарайта (угол в пи)
				(*cub_file)->sprites[i][5] = -1; // конец спарайта (угол в пи)
				(*cub_file)->sprites[i][6] = -1; // ширина спарайта (угол в пи)
				(*cub_file)->sprites[i][7] = -1; // len_of_c (высота спрайта по его центру для отрисовки)
				i++;
			}
			x += (*cub_file)->scale;
		}
		x = 0;
		y += (*cub_file)->scale;
	}

	return (0);
}

int 		count_sprites(char *map) // ok
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