/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:41:53 by btammara          #+#    #+#             */
/*   Updated: 2021/02/03 10:53:27 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void				ft_screenshot(t_parse **cub_file, char *s1)
{
	int fd;
	unsigned int n = 0;
	signed int s = 0;
	unsigned int size = 0;

	if (ft_strncmp(s1, "--save", 6) != 0)
		ft_error("cub3D works only with \"--save\"");

	if ((fd = open("cub3D.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
	{
		printf ("cannot create a new .bmp file\n");
		exit(1);
	}
	write(fd, "BM", 2);
	size = 54 + ((*cub_file)->Ry * (*cub_file)->Rx) * (*cub_file)->bits_per_pixel;
	write(fd, &size, 4); // общий размер файла
	write(fd, &n, 2);
	write(fd, &n, 2);
	n = 54;
	write(fd, &n, 4); // на сколько байт сместить до actual pixel data in bytes ИСПРАВЬ (сейчас это 54)

	n = 40;
	write(fd, &n, 4);
	write(fd, &(*cub_file)->Rx, 4);
	write(fd, &(*cub_file)->Ry, 4);
	n = 1;
	write(fd, &n, 2);
	write(fd, &(*cub_file)->bits_per_pixel, 2);
	n = 0;
	write(fd, &n, 4);
	write(fd, &n, 4);
	s = 0;
	write(fd, &s, 4);
	write(fd, &s, 4);
	write(fd, &n, 4);
	write(fd, &n, 4);

	s = (*cub_file)->Ry;

	while (s > 0)
	{
		s--;
		write(fd, (*cub_file)->addr + (s * (*cub_file)->line_length), (*cub_file)->Rx * ((*cub_file)->bits_per_pixel / 8));
	}
	close(fd);
	exit(0);
}