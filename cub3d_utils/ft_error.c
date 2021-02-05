/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 08:54:25 by btammara          #+#    #+#             */
/*   Updated: 2021/01/31 09:00:13 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *text)
{
	size_t i = 0;
	size_t len = ft_strlen(text);
	
	while (i < len)
	{
		write(2, &text[i++], sizeof(char));
	}
	write(2, "\n", sizeof(char));
	exit(1);
}