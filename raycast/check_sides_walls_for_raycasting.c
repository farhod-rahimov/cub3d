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

#include "../cub3d.h"

char	check_sides_walls_for_raycasting(t_parse **cub_file) //ok
{
	static char storona = 'O'; // измени в заисимости от player_a - 30 градусов

	if ((*cub_file)->FOV >= 0)
	{
		if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 0 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 90) // lower right
		{
			if (check_lower_side_walls(cub_file, 0) <= check_right_side_walls(cub_file, 0))
			{
				if (storona == 'E')
				{
					check_lower_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
						check_right_side_walls(cub_file, 0);
					else
						storona = 'S';
				}
				else 
				{
					check_lower_side_walls(cub_file, 0);
					storona = 'S';
				}
			}
			else
			{
				if (storona == 'S')
				{
					// check_right_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
					{
						if (check_lower_side_walls(cub_file, 0) - check_right_side_walls(cub_file, 0) > (*cub_file)->scale / 3)
						{
							// check_right_side_walls(cub_file, 0); 
							storona = 'E';
						}
						else
							check_lower_side_walls(cub_file, 0);
					}
					else
						storona = 'E';
				}
				else
				{
					// check_right_side_walls(cub_file, 0); 
					storona = 'E';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 90 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 180) // lower left
		{
			if (check_lower_side_walls(cub_file, 0) <= check_left_side_walls(cub_file, 0) * -1)
			{
				if (storona == 'W')
				{
					check_lower_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
					{
						if ((check_left_side_walls(cub_file, 0) * -1) - check_lower_side_walls(cub_file, 0) > (*cub_file)->scale / 3)
						{
							// check_lower_side_walls(cub_file, 0);
							storona = 'S';
						}
						else
							check_left_side_walls(cub_file, 0); 
					}
					else
						storona = 'S';
				}
				else
				{
					check_lower_side_walls(cub_file, 0);
					storona = 'S';
				}
			}
			else
			{
				if (storona == 'S')
				{
					// check_left_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_lower_side_walls(cub_file, 0);
					else
						storona = 'W';
				}
				else
				{
					// check_left_side_walls(cub_file, 0); 
					storona = 'W';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 180 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 270) // upper left
		{
			if (check_upper_side_walls(cub_file, 0) * -1 <= check_left_side_walls(cub_file, 0) * -1) // было < 
			{
				if (storona == 'W')
				{
					check_upper_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_left_side_walls(cub_file, 0); 
					else
						storona = 'N';
				}
				else
				{
					check_upper_side_walls(cub_file, 0);
					storona = 'N';
				}
			}
			else
			{
				if (storona == 'N')
				{
					// check_left_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_upper_side_walls(cub_file, 0);
					else
						storona = 'W';
				}
				else
				{
					// check_left_side_walls(cub_file, 0); 
					storona = 'W';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 >= 270 && (int)((*cub_file)->FOV * 180 / PI) % 360 < 360) // upper right
		{
			if (check_upper_side_walls(cub_file, 0) * -1 <= check_right_side_walls(cub_file, 0))
			{
				if (storona == 'E')
				{
					check_upper_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
					{
						if (check_right_side_walls(cub_file, 0) - check_upper_side_walls(cub_file, 0) * -1 > (*cub_file)->scale / 3)
						{
							// check_upper_side_walls(cub_file, 0); 
							storona = 'N';
						}
						else
							check_right_side_walls(cub_file, 0); 
					}
					else
						storona = 'N';
				}
				else
				{
					check_upper_side_walls(cub_file, 0);
					storona = 'N';
				}
			}
			else
			{
				if (storona == 'N')
				{
					// check_right_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
						check_upper_side_walls(cub_file, 0);
					else
						storona = 'E';
				}
				else
				{
					// check_right_side_walls(cub_file, 0); 
					storona = 'E';
				}
			}
		}
	}
	else
	{
		if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= 0 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -90) // upper right
		{
			if (check_upper_side_walls(cub_file, 0) * -1 <= check_right_side_walls(cub_file, 0))
			{
				if (storona == 'E')
				{
					check_upper_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
					{
						if (check_right_side_walls(cub_file, 0) - check_upper_side_walls(cub_file, 0) * -1 > (*cub_file)->scale / 3)
						{
							// check_upper_side_walls(cub_file, 0); 
							storona = 'N';
						}
						else
							check_right_side_walls(cub_file, 0); 
					}
					else
						storona = 'N';
				}
				else
				{
					check_upper_side_walls(cub_file, 0);
					storona = 'N';
				}
			}
			else
			{
				if (storona == 'N')
				{
					// check_right_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
						check_upper_side_walls(cub_file, 0);
					else
						storona = 'E';
				}
				else
				{
					// check_right_side_walls(cub_file, 0); 
					storona = 'E';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -90 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -180) // upper left
		{
			if (check_upper_side_walls(cub_file, 0) * -1 <= check_left_side_walls(cub_file, 0) * -1) // было < 
			{
				if (storona == 'W')
				{
					check_upper_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_left_side_walls(cub_file, 0); 
					else
						storona = 'N';
				}
				else
				{
					check_upper_side_walls(cub_file, 0);
					storona = 'N';
				}
			}
			else
			{
				if (storona == 'N')
				{
					// check_left_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 0 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_upper_side_walls(cub_file, 0);
					else
						storona = 'W';
				}
				else
				{
					// check_left_side_walls(cub_file, 0); 
					storona = 'W';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -180 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -270) // lower left
		{
			if (check_lower_side_walls(cub_file, 0) <= check_left_side_walls(cub_file, 0) * -1)
			{
				if (storona == 'W')
				{
					check_lower_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
					{
						if ((check_left_side_walls(cub_file, 0) * -1) - check_lower_side_walls(cub_file, 0) > (*cub_file)->scale / 3)
						{
							// check_lower_side_walls(cub_file, 0);
							storona = 'S';
						}
						else
							check_left_side_walls(cub_file, 0); 
					}
					else
						storona = 'S';
				}
				else
				{
					check_lower_side_walls(cub_file, 0);
					storona = 'S';
				}
			}
			else
			{
				if (storona == 'S')
				{
					// check_left_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 0)
						check_lower_side_walls(cub_file, 0);
					else
						storona = 'W';
				}
				else
				{
					// check_left_side_walls(cub_file, 0); 
					storona = 'W';
				}
			}
		}
		else if ((int)((*cub_file)->FOV * 180 / PI) % 360 <= -270 && (int)((*cub_file)->FOV * 180 / PI) % 360 > -360) // lower right
		{
			if (check_lower_side_walls(cub_file, 0) <= check_right_side_walls(cub_file, 0))
			{
				if (storona == 'E')
				{
					check_lower_side_walls(cub_file, 0);
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
						check_right_side_walls(cub_file, 0);
					else
						storona = 'S';
				}
				else 
				{
					check_lower_side_walls(cub_file, 0);
					storona = 'S';
				}
			}
			else
			{
				if (storona == 'S')
				{
					// check_right_side_walls(cub_file, 0); 
					if (((int)(*cub_file)->c_y + 1) % (*cub_file)->scale == 1 && ((int)(*cub_file)->c_x + 1) % (*cub_file)->scale == 1)
					{
						if (check_lower_side_walls(cub_file, 0) - check_right_side_walls(cub_file, 0) > (*cub_file)->scale / 3)
						{
							// check_right_side_walls(cub_file, 0); 
							storona = 'E';
						}
						else
							check_lower_side_walls(cub_file, 0);
					}
					else
						storona = 'E';
				}
				else
				{
					// check_right_side_walls(cub_file, 0); 
					storona = 'E';
				}
			}
		}
	}
	return (storona);
}