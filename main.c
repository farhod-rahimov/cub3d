/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:03:44 by btammara          #+#    #+#             */
/*   Updated: 2020/12/14 17:03:23 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
// gcc main.c libmlx.dylib -framework OpenGl -framework Appkit

int main(void)
{
    void	*mlx;
    void	*window;
    int		x;
    int		y;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 640, 480, "test");
    x = 100;
    y = 100;
    while(y++ < 200)
    {
        x = 100;
        while (x++ < 200)
            mlx_pixel_put(mlx, window, x, y, 0xFFFFFF);
    }
    mlx_loop(mlx);

	char a[1][1];
	printf("%s\n", a[1]);
	a[2][2];
	printf("%s\n", a[1]);
	printf("%s\n", a[2]);

    return 0;
}