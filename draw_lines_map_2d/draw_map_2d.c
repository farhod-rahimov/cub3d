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

#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
#include "../cub3d.h"
// gcc test.c libmlx.dylib -framework OpenGl -framework Appkit

void draw_map_2d(t_parse *cub_file, int x, int y)
{
	while (cub_file->map2d[y][x])
	{
		while (cub_file->map2d[y][x])
		{
			if (cub_file->map2d[y][x] == '1' || cub_file->map2d[y][x] == '6' || cub_file->map2d[y][x] == '7' || cub_file->map2d[y][x] == '8' || cub_file->map2d[y][x] == '9')
				my_mlx_pixel_put(cub_file, x, y, 0x074517); // dark green
			// else if (cub_file->map2d[y][x] == 'N' || cub_file->map2d[y][x] == 'S'
			// || cub_file->map2d[y][x] == 'E' || cub_file->map2d[y][x] == 'W')
			// 	my_mlx_pixel_put(cub_file, x, y, 0x7a0505); // dark red // на карте больше нет этих букв, удали это
			else if (cub_file->map2d[y][x] == '2')
				my_mlx_pixel_put(cub_file, x, y, 0x5c5a19); // dark yellow
			else if (cub_file->map2d[y][x] == ' ')
				my_mlx_pixel_put(cub_file, x, y, 0x0e5859); // dark blue
			x++;
		}
		x = 0;
		y++;
	}
	int a = 0; // draw player_position /////// DELETE
	int b = 0;
	while (b < 5)
	{
		while (a < 5)
		{
			cub_file->c_x = cub_file->player_x + a;
			my_mlx_pixel_put(cub_file, (int)cub_file->c_x, cub_file->player_y + b, 0xffffff);
			a++;
		}
		a = 0;
		b++;
	}

	while (a < 20) // draw player_a
	{
		cub_file->c_x = cub_file->player_x + a * cosl(cub_file->player_a);
		cub_file->c_y = cub_file->player_y + a * sinl(cub_file->player_a);
		my_mlx_pixel_put(cub_file, (int)cub_file->c_x, (int)cub_file->c_y, 0x00ff00);
		a++;
	}  ///// DELETE
	
	
	cub_file->len_of_c = 0;
	cub_file->FOV = cub_file->player_a - (PI / 6);
	// cub_file->FOV = cub_file->player_a;
	static char storona;
	// static int iaa;

	while (cub_file->FOV <= cub_file->player_a + (PI / 6)) // hit_y
	{
		// len_of_c upper (-)
		// len_of_c lower (+)
		// len_of_c left (-)
		// len_of_c right (+)
		// printf("FOV %f\n", cub_file->FOV * 180 / PI);
		if (cub_file->FOV >= 0)
		{
			if ((int)(cub_file->FOV * 180 / PI) % 360 >= 0 && (int)(cub_file->FOV * 180 / PI) % 360 < 90) // lower right
			{
				if (check_lower_side_walls(cub_file, 0) <= check_right_side_walls(cub_file, 0))
				{
					if (storona == 'E')
					{
						check_lower_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							check_right_side_walls(cub_file, 0);
							draw_right_side_walls(cub_file);
						}
						else
						{
							storona = 'S';
							draw_lower_side_walls(cub_file);
						}
					}
					else 
					{
						check_lower_side_walls(cub_file, 0);
						storona = 'S';
						draw_lower_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'S')
					{
						check_right_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							if (check_lower_side_walls(cub_file, 0) - check_right_side_walls(cub_file, 0) > SCALE / 3)
							{
								check_right_side_walls(cub_file, 0); 
								storona = 'E';
								draw_right_side_walls(cub_file);
							}
							else
							{
								check_lower_side_walls(cub_file, 0);
								draw_lower_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'E';
							draw_right_side_walls(cub_file);
						}
					}
					else
					{
						check_right_side_walls(cub_file, 0); 
						storona = 'E';
						draw_right_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 90 && (int)(cub_file->FOV * 180 / PI) % 360 < 180) // lower left
			{
				if (check_lower_side_walls(cub_file, 0) <= check_left_side_walls(cub_file, 0) * -1)
				{
					if (storona == 'W')
					{
						check_lower_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							if ((check_left_side_walls(cub_file, 0) * -1) - check_lower_side_walls(cub_file, 0) > SCALE / 3)
							{
								check_lower_side_walls(cub_file, 0);
								storona = 'S';
								draw_lower_side_walls(cub_file);
							}
							else
							{
								check_left_side_walls(cub_file, 0); 
								draw_left_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'S';
							draw_lower_side_walls(cub_file);
						}
					}
					else
					{
						check_lower_side_walls(cub_file, 0);
						storona = 'S';
						draw_lower_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'S')
					{
						check_left_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_lower_side_walls(cub_file, 0);
							draw_lower_side_walls(cub_file);
						}
						else
						{
							storona = 'W';
							draw_left_side_walls(cub_file);
						}
					}
					else
					{
						check_left_side_walls(cub_file, 0); 
						storona = 'W';
						draw_left_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 180 && (int)(cub_file->FOV * 180 / PI) % 360 < 270) // upper left
			{
				if (check_upper_side_walls(cub_file, 0) * -1 <= check_left_side_walls(cub_file, 0) * -1) // было < 
				{
					if (storona == 'W')
					{
						check_upper_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_left_side_walls(cub_file, 0); 
							draw_left_side_walls(cub_file);
						}
						else
						{
							storona = 'N';
							draw_upper_side_walls(cub_file);
						}
					}
					else
					{
						check_upper_side_walls(cub_file, 0);
						storona = 'N';
						draw_upper_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'N')
					{
						check_left_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_upper_side_walls(cub_file, 0);
							draw_upper_side_walls(cub_file);
						}
						else
						{
							storona = 'W';
							draw_left_side_walls(cub_file);
						}
					}
					else
					{
						check_left_side_walls(cub_file, 0); 
						storona = 'W';
						draw_left_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 >= 270 && (int)(cub_file->FOV * 180 / PI) % 360 < 360) // upper right
			{
				if (check_upper_side_walls(cub_file, 0) * -1 <= check_right_side_walls(cub_file, 0))
				{
					if (storona == 'E')
					{
						check_upper_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							if (check_right_side_walls(cub_file, 0) - check_upper_side_walls(cub_file, 0) * -1 > SCALE / 3)
							{
								check_upper_side_walls(cub_file, 0); 
								storona = 'N';
								draw_upper_side_walls(cub_file);
							}
							else
							{
								check_right_side_walls(cub_file, 0); 
								draw_right_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'N';
							draw_upper_side_walls(cub_file);
						}
					}
					else
					{
						check_upper_side_walls(cub_file, 0);
						storona = 'N';
						draw_upper_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'N')
					{
						check_right_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							check_upper_side_walls(cub_file, 0);
							draw_upper_side_walls(cub_file);
						}
						else
						{
							storona = 'E';
							draw_right_side_walls(cub_file);
						}
					}
					else
					{
						check_right_side_walls(cub_file, 0); 
						storona = 'E';
						draw_right_side_walls(cub_file);
					}
				}
			}
		}
		else
		{
			if ((int)(cub_file->FOV * 180 / PI) % 360 <= 0 && (int)(cub_file->FOV * 180 / PI) % 360 > -90) // upper right
			{
				if (check_upper_side_walls(cub_file, 0) * -1 <= check_right_side_walls(cub_file, 0))
				{
					if (storona == 'E')
					{
						check_upper_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							if (check_right_side_walls(cub_file, 0) - check_upper_side_walls(cub_file, 0) * -1 > SCALE / 3)
							{
								check_upper_side_walls(cub_file, 0); 
								storona = 'N';
								draw_upper_side_walls(cub_file);
							}
							else
							{
								check_right_side_walls(cub_file, 0); 
								draw_right_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'N';
							draw_upper_side_walls(cub_file);
						}
					}
					else
					{
						check_upper_side_walls(cub_file, 0);
						storona = 'N';
						draw_upper_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'N')
					{
						check_right_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							check_upper_side_walls(cub_file, 0);
							draw_upper_side_walls(cub_file);
						}
						else
						{
							storona = 'E';
							draw_right_side_walls(cub_file);
						}
					}
					else
					{
						check_right_side_walls(cub_file, 0); 
						storona = 'E';
						draw_right_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -90 && (int)(cub_file->FOV * 180 / PI) % 360 > -180) // upper left
			{
				if (check_upper_side_walls(cub_file, 0) * -1 <= check_left_side_walls(cub_file, 0) * -1) // было < 
				{
					if (storona == 'W')
					{
						check_upper_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_left_side_walls(cub_file, 0); 
							draw_left_side_walls(cub_file);
						}
						else
						{
							storona = 'N';
							draw_upper_side_walls(cub_file);
						}
					}
					else
					{
						check_upper_side_walls(cub_file, 0);
						storona = 'N';
						draw_upper_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'N')
					{
						check_left_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 0 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_upper_side_walls(cub_file, 0);
							draw_upper_side_walls(cub_file);
						}
						else
						{
							storona = 'W';
							draw_left_side_walls(cub_file);
						}
					}
					else
					{
						check_left_side_walls(cub_file, 0); 
						storona = 'W';
						draw_left_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -180 && (int)(cub_file->FOV * 180 / PI) % 360 > -270) // lower left
			{
				if (check_lower_side_walls(cub_file, 0) <= check_left_side_walls(cub_file, 0) * -1)
				{
					if (storona == 'W')
					{
						check_lower_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							if ((check_left_side_walls(cub_file, 0) * -1) - check_lower_side_walls(cub_file, 0) > SCALE / 3)
							{
								check_lower_side_walls(cub_file, 0);
								storona = 'S';
								draw_lower_side_walls(cub_file);
							}
							else
							{
								check_left_side_walls(cub_file, 0); 
								draw_left_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'S';
							draw_lower_side_walls(cub_file);
						}
					}
					else
					{
						check_lower_side_walls(cub_file, 0);
						storona = 'S';
						draw_lower_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'S')
					{
						check_left_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 0)
						{
							check_lower_side_walls(cub_file, 0);
							draw_lower_side_walls(cub_file);
						}
						else
						{
							storona = 'W';
							draw_left_side_walls(cub_file);
						}
					}
					else
					{
						check_left_side_walls(cub_file, 0); 
						storona = 'W';
						draw_left_side_walls(cub_file);
					}
				}
			}
			else if ((int)(cub_file->FOV * 180 / PI) % 360 <= -270 && (int)(cub_file->FOV * 180 / PI) % 360 > -360) // lower right
			{
				if (check_lower_side_walls(cub_file, 0) <= check_right_side_walls(cub_file, 0))
				{
					if (storona == 'E')
					{
						check_lower_side_walls(cub_file, 0);
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							check_right_side_walls(cub_file, 0);
							draw_right_side_walls(cub_file);
						}
						else
						{
							storona = 'S';
							draw_lower_side_walls(cub_file);
						}
					}
					else 
					{
						check_lower_side_walls(cub_file, 0);
						storona = 'S';
						draw_lower_side_walls(cub_file);
					}
				}
				else
				{
					if (storona == 'S')
					{
						check_right_side_walls(cub_file, 0); 
						if (((int)cub_file->c_y + 1) % SCALE == 1 && ((int)cub_file->c_x + 1) % SCALE == 1)
						{
							if (check_lower_side_walls(cub_file, 0) - check_right_side_walls(cub_file, 0) > SCALE / 3)
							{
								check_right_side_walls(cub_file, 0); 
								storona = 'E';
								draw_right_side_walls(cub_file);
							}
							else
							{
								check_lower_side_walls(cub_file, 0);
								draw_lower_side_walls(cub_file);
							}
						}
						else
						{
							storona = 'E';
							draw_right_side_walls(cub_file);
						}
					}
					else
					{
						check_right_side_walls(cub_file, 0); 
						storona = 'E';
						draw_right_side_walls(cub_file);
					}
				}
			}
		}
		// cub_file->FOV += PI / 180;
		cub_file->FOV += (PI / 3) / cub_file->Rx;
	}
}