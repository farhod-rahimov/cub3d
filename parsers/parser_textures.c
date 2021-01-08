/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:22:49 by btammara          #+#    #+#             */
/*   Updated: 2020/12/18 16:15:15 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../get_next_line/get_next_line.h"

int	get_resolution(t_parse **cub_file, int i)
{
	char	*tmp_str;
	
	if ((*cub_file)->Rx > 0 || (*cub_file)->Ry > 0)
		return (-1);
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;
	if (((*cub_file)->Rx = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_str = (*cub_file)->p_file + i;
	if (((*cub_file)->Ry = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("Rx %d\n", (*cub_file)->Rx);
    printf("Ry %d\n", (*cub_file)->Ry);
	i = parse2(cub_file, i);
	return (i);
}

int	get_north_texture(t_parse **cub_file, int i)
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->NO != NULL)
		return (-1);
	i = i + 1;
	if ((*cub_file)->p_file[i++] != 'O' && ((*cub_file)->p_file[i] != ' '))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->NO = ft_substr((*cub_file)->p_file, tmp_i, len)))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("NO %s\n", (*cub_file)->NO);
	i = parse2(cub_file, i);
	return (i);
}

int	get_south_texture(t_parse **cub_file, int i)
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->SO != NULL)
		return (-1);
	i = i + 1;
	if ((*cub_file)->p_file[i++] != 'O' && ((*cub_file)->p_file[i] != ' '))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->SO = ft_substr((*cub_file)->p_file, tmp_i, len)))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("SO %s\n", (*cub_file)->SO);
	i = parse2(cub_file, i);
	return (i);
}

int	get_west_texture(t_parse **cub_file, int i)
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->WE != NULL)
		return (-1);
	i = i + 1;
	if ((*cub_file)->p_file[i++] != 'O' && ((*cub_file)->p_file[i] != ' '))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->WE = ft_substr((*cub_file)->p_file, tmp_i, len)))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("WE %s\n", (*cub_file)->WE);
	i = parse2(cub_file, i);
	return (i);
}

int	get_east_texture(t_parse **cub_file, int i)
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->EA != NULL)
		return (-1);
	i = i + 1;
	if ((*cub_file)->p_file[i++] != 'A' && ((*cub_file)->p_file[i] != ' '))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->EA = ft_substr((*cub_file)->p_file, tmp_i, len)))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("EA %s\n", (*cub_file)->EA);
	i = parse2(cub_file, i);
	return (i);
}

int	get_sprite_texture(t_parse **cub_file, int i)
{
	int		tmp_i;
	int		len;

	if ((*cub_file)->S != NULL)
		return (-1);
	i = i + 1;
	if ((*cub_file)->p_file[i] != ' ')
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
	tmp_i = i;
	while ((*cub_file)->p_file[i] != ' ' && (*cub_file)->p_file[i] != '\n')
		i++;
	len = i - tmp_i;
	if (!((*cub_file)->S = ft_substr((*cub_file)->p_file, tmp_i, len)))
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("S %s\n", (*cub_file)->S);
	i = parse2(cub_file, i);
	return(i);
}

int	get_floor_color(t_parse **cub_file, int i)
{
	char	*tmp_str;
	
	if ((*cub_file)->Fr > 0 || (*cub_file)->Fg > 0 || (*cub_file)->Fb > 0)
		return (-1);
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;

	tmp_str = (*cub_file)->p_file + i;				// Fr
	if (((*cub_file)->Fr = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		return (-1);

	tmp_str = (*cub_file)->p_file + i;				// Fg
	if (((*cub_file)->Fg = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		return (-1);

	tmp_str = (*cub_file)->p_file + i;				//  Fb
	if (((*cub_file)->Fb = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("Fr %d\n", (*cub_file)->Fr);
    printf("Fg %d\n", (*cub_file)->Fg);
    printf("Fb %d\n", (*cub_file)->Fb);
	i = parse2(cub_file, i);
	return (i);
}

int	get_ceiling_color(t_parse **cub_file, int i)
{
	char	*tmp_str;
	
	if ((*cub_file)->Cr > 0 || (*cub_file)->Cg > 0 || (*cub_file)->Cb > 0)
		return (-1);
	i++;
	if ((*cub_file)->p_file[i] != ' ')
		return (-1);
	while ((*cub_file)->p_file[i] == ' ')
		i++;

	tmp_str = (*cub_file)->p_file + i;				// Cr
	if (((*cub_file)->Cr = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		return (-1);

	tmp_str = (*cub_file)->p_file + i;				// Cg
	if (((*cub_file)->Cg = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	if ((*cub_file)->p_file[i++] != ',')
		return (-1);

	tmp_str = (*cub_file)->p_file + i;				//  Cb
	if (((*cub_file)->Cb = ft_atoi(tmp_str)) < 0)
		return (-1);
	while((ft_isdigit((*cub_file)->p_file[i])))
		i++;
	while ((*cub_file)->p_file[i] == ' ')
		i++;
    printf("Cr %d\n", (*cub_file)->Cr);
    printf("Cg %d\n", (*cub_file)->Cg);
    printf("Cb %d\n", (*cub_file)->Cb);
	i = parse2(cub_file, i);
	return (i);
}