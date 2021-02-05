/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2021/02/05 10:11:26 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_resolution(t_parse **cub_file, int i) //ok
{
	char	*tmp_str;
	int 	a;
	int		x;
	int		y;
	mlx_get_screen_size((*cub_file)->mlx, &x, &y);
	
	if ((*cub_file)->Rx > 0 || (*cub_file)->Ry > 0)
		ft_error(".cub file has more than 1 resolution");
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		ft_error("in .cub file the resolution should be written like \"R 800 500\"");
		
	while ((*cub_file)->p_file[i] == ' ')
		i++;

	if (!ft_isdigit((*cub_file)->p_file[i]))
		ft_error("resolution is wrong. It should be written like \"R 800 500\"");
	tmp_str = (*cub_file)->p_file + i;

	if (((*cub_file)->Rx = ft_atoi(tmp_str)) <= 0)
		ft_error("resolution cannot be negative or less than 1");
	else if ((*cub_file)->Rx > x)
		(*cub_file)->Rx = x;

	a = i;
	while (ft_isdigit((*cub_file)->p_file[a]))
		a++;
	if (a - i > 6)
		(*cub_file)->Rx = x;
	
	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;

	if (!ft_isdigit((*cub_file)->p_file[i]))
		ft_error("resolution is wrong. It should be written like \"R 800 500\"");
	tmp_str = (*cub_file)->p_file + i;
	if (((*cub_file)->Ry = ft_atoi(tmp_str)) <= 0)
		ft_error("resolution cannot be negative or less than 1");
	else if ((*cub_file)->Ry > y)
		(*cub_file)->Ry = y;
	
	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		(*cub_file)->Ry = y;

	i = a;	
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("resolution has excessive symbols. It should be written like \"R 800 500\"");

	i = parse2(cub_file, i);
	return (i);
}

int	get_north_texture(t_parse **cub_file, int i) //ok
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->NO != NULL)
		ft_error(".cub file has more than 1 path to NORTH TEXTURE");
	i++;
	if ((*cub_file)->p_file[i++] != 'O' && ((*cub_file)->p_file[i] != ' '))
		ft_error("path to NORTH TEXTURE is wrong. It should be written like \"NO /Users/btammara/Desktop/north_1.xpm\"");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->NO = ft_substr((*cub_file)->p_file, tmp_i, len)))
		ft_error("cannot allocate memmory for copying a path to NORTH TEXTURE");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("path to NORTH TEXTURE is wrong (it has excessive symbols). It should be written like \"NO /Users/btammara/Desktop/north_1.xpm\"");
	i = parse2(cub_file, i);
	return (i);
}

int	get_south_texture(t_parse **cub_file, int i) //ok
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->SO != NULL)
		ft_error(".cub file has more than 1 path to SOUTH TEXTURE");
	i += 2;
	if (((*cub_file)->p_file[i] != ' '))
		ft_error("path to SOUTH TEXTURE is wrong. It should be written like \"SO /Users/btammara/Desktop/south_1.xpm\"");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->SO = ft_substr((*cub_file)->p_file, tmp_i, len)))
		ft_error("cannot allocate memmory for copying a path to SOUTH TEXTURE");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("path to SOUTH TEXTURE is wrong (it has excessive symbols). It should be written like \"SO /Users/btammara/Desktop/south_1.xpm\"");
	i = parse2(cub_file, i);
	return (i);
}

int	get_west_texture(t_parse **cub_file, int i) //ok
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->WE != NULL)
		ft_error(".cub file has more than 1 path to WEST TEXTURE");
	i++;
	if ((*cub_file)->p_file[i++] != 'E' && ((*cub_file)->p_file[i] != ' '))
		ft_error("path to WEST TEXTURE is wrong. It should be written like \"WE /Users/btammara/Desktop/west_1.xpm\"");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->WE = ft_substr((*cub_file)->p_file, tmp_i, len)))
		ft_error("cannot allocate memmory for copying a path to WEST TEXTURE");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("path to WEST TEXTURE is wrong (it has excessive symbols). It should be written like \"WE /Users/btammara/Desktop/west_1.xpm\"");
	i = parse2(cub_file, i);
	return (i);
}

int	get_east_texture(t_parse **cub_file, int i) //ok
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->EA != NULL)
		ft_error(".cub file has more than 1 path to EAST TEXTURE");
	i++;
	if ((*cub_file)->p_file[i++] != 'A' && ((*cub_file)->p_file[i] != ' '))
		ft_error("path to EAST TEXTURE is wrong. It should be written like \"EA /Users/btammara/Desktop/east_1.xpm\"");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->EA = ft_substr((*cub_file)->p_file, tmp_i, len)))
		ft_error("cannot allocate memmory for copying a path to EAST TEXTURE");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("path to EAST TEXTURE is wrong (it has excessive symbols). It should be written like \"EA /Users/btammara/Desktop/east_1.xpm\"");
	i = parse2(cub_file, i);
	return (i);
}

int	get_sprite_texture(t_parse **cub_file, int i) //ok
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->S != NULL)
		ft_error(".cub file has more than 1 path to SPRITE TEXTURE");
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		ft_error("path to SPRITE TEXTURE is wrong. It should be written like \"S /Users/btammara/Desktop/sprite_1.xpm\"");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->S = ft_substr((*cub_file)->p_file, tmp_i, len)))
		ft_error("cannot allocate memmory for copying a path to SPRITE TEXTURE");
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i] != '\n')
		ft_error("path to SPRITE TEXTURE is wrong (it has excessive symbols). It should be written like \"S /Users/btammara/Desktop/sprite_1.xpm\"");
	i = parse2(cub_file, i);
	return(i);
}

int	get_floor_color(t_parse **cub_file, int i) //ok
{
	char	*tmp_str;
	int		a;
	
	if ((*cub_file)->floor[0] > 0 || (*cub_file)->floor[1] > 0 || (*cub_file)->floor[2] > 0)
		ft_error(".cub file has more than 1 floor color");
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		ft_error("floor color is wrong. It should be written like \"F 255, 255, 255\"");
/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				// Fr
	if (((*cub_file)->floor[0] = ft_atoi(tmp_str)) < 0 || (*cub_file)->floor[0] > 255)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");

	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");

	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		ft_error("floor color is wrong. Each element of floor color should be separated by comma ','");
/***********************************************************************************************************/


/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				// Fg
	if (((*cub_file)->floor[1] = ft_atoi(tmp_str)) < 0 || (*cub_file)->floor[1] > 255)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");
		
	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");
	
	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		ft_error("floor color is wrong. Each element of floor color should be separated by comma ','");
/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				//  Fb
	if (((*cub_file)->floor[2] = ft_atoi(tmp_str)) < 0 || (*cub_file)->floor[2] > 255)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");

	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("floor color is wrong. Each element of floor color can be between 0 and 255");
	
	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != '\n')
		ft_error("floor color is wrong (it has excessive symbols). It should be written like \"F 255, 255, 255\"");
	i = parse2(cub_file, i);
	return (i);
}

int	get_ceiling_color(t_parse **cub_file, int i) //ok
{
	char	*tmp_str;
	int		a;
	
	if ((*cub_file)->ceilling[0] > 0 || (*cub_file)->ceilling[1] > 0 || (*cub_file)->ceilling[2] > 0)
		ft_error(".cub file has more than 1 ceilling color");
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		ft_error("ceilling color is wrong. It should be written like \"C 255, 255, 255\"");
/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				// Cr
	if (((*cub_file)->ceilling[0] = ft_atoi(tmp_str)) < 0 || (*cub_file)->ceilling[0] > 255)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");

	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");

	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		ft_error("ceilling color is wrong. Each element of ceilling color should be separated by comma ','");
/***********************************************************************************************************/


/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				// Cg
	if (((*cub_file)->ceilling[1] = ft_atoi(tmp_str)) < 0 || (*cub_file)->ceilling[1] > 255)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");
		
	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");
	
	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		ft_error("ceilling color is wrong. Each element of ceilling color should be separated by comma ','");
/***********************************************************************************************************/
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;				//  Cb
	if (((*cub_file)->ceilling[2] = ft_atoi(tmp_str)) < 0 || (*cub_file)->ceilling[2] > 255)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");

	a = i;
	while((ft_isdigit((*cub_file)->p_file[a])))
		a++;
	if (a - i > 6)
		ft_error("ceilling color is wrong. Each element of ceilling color can be between 0 and 255");
	
	i = a;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	if ((*cub_file)->p_file[i++] != '\n')
		ft_error("ceilling color is wrong (it has excessive symbols). It should be written like \"C 255, 255, 255\"");
	i = parse2(cub_file, i);
	return (i);
}