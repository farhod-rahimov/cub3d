/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:46 by btammara          #+#    #+#             */
/*   Updated: 2021/02/03 15:39:36 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3d_H
# define CUB_3d_H

# include <stdlib.h>
# include <stdio.h> //perror
# include <string.h> //str error
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./get_next_line/get_next_line.h"
#include "/Users/btammara/projects/cub3d/minilibx_mms_20200219/mlx.h"
// #define SCALE 80 // 300 300 ok
// #define SCALE 50 // 200 200 ok
// #define SCALE 30 // 100 100 ok
// #define SCALE 20 // 50 50 +- ok
#define SCALE 25 // 30 30 +- ok
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091
typedef	struct		s_parse
{
    char    *p_file;
    signed int	Rx;
    signed int	Ry;
	char    *NO;
	char    *SO;
	char    *WE;
	char    *EA;
    char    *S;
    int     floor[3];
    int     ceilling[3];

    char    *map;
    int		map_x;
    int		map_y;
	char	**map2d_1; // free! every string, then free *
	char	**map2d; // free! every string, then free *
	int		player_x;
	int		player_y;
	long double	player_a;
	long double	FOV;
	int			tmp_x;
	long double	len_of_c;
	long double	c_x;
	// int		c_x;
	long double	c_y;
	// int		c_y;
	char	p_of_view;
	int scale;

	char	side;
	char	storona;
	int		shirina;
	long double example;
 
	long double	**sprites;
	long double	array_walls[5000];
	long double	***array_sprites;
//	long double	FOV_sprite;
	int			num_of_sprites;

    void        *mlx;
    void        *win;
    void        *img;

	int			height;

    void        *img_north;
	int			width_north;
	int			height_north;

    void        *img_south;
	int			width_south;
	int			height_south;
 
    void        *img_west;
	int			width_west;
	int			height_west;
 
    void        *img_east;
	int			width_east;
	int			height_east;
 
    void        *img_sprite;
	int			width_sprite;
	int			height_sprite;

	char        *addr;
    char        *addr_text;
    int         bits_per_pixel;
    int         bits_per_pixel_text;
    int         line_length;
    int         line_length_text;
    int         endian;;
    int         endian_text;

}					t_parse;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	int			player_x;
	int			player_y;
	int			map_x;
	int			map_y;
}               t_vars;  // for int key_hook()

int					get_next_line(int fd, char **line);
t_parse				*create_new_elem(void);

void				parse(int fd, t_parse **cub_file);
int					parse2(t_parse **cub_file, int i);
int					get_resolution(t_parse **cub_file, int i);
int					get_north_texture(t_parse **cub_file, int i);
int					get_south_texture(t_parse **cub_file, int i);
int					get_west_texture(t_parse **cub_file, int i);
int					get_east_texture(t_parse **cub_file, int i);
int					get_sprite_texture(t_parse **cub_file, int i);
int					get_floor_color(t_parse **cub_file, int i);
int					get_ceiling_color(t_parse **cub_file, int i);
int					get_map(t_parse **cub_file, int i);


int					get_coordinate_of_spites(t_parse **cub_file);
int 				count_sprites(char *map);
void 				match_sprites(t_parse **cub_file);
int					convert_map(t_parse **cub_file);
int					convert_map2d_1(t_parse **cub_file);
int					check_if_map_is_last(t_parse **cub_file);
int					check_if_parsed_file_is_ok(t_parse **cub_file);
void				check_if_resolution_is_ok(t_parse **cub_file);
int					check_if_floor_color_is_ok(t_parse **cub_file);
int					check_if_ceiling_color_is_ok(t_parse **cub_file);
int					check_if_map_is_ok(t_parse **cub_file);
void				check_map_left_to_right(t_parse **cub_file, int x, int y, int flag);
void				check_map_up_to_down(t_parse **cub_file, int x, int y, int flag);
void				check_closed_spaces(t_parse **cub_file);

long double				check_upper_side_walls(t_parse **cub_file, int i);
long double				check_lower_side_walls(t_parse **cub_file, int i);
long double				check_right_side_walls(t_parse **cub_file, int i);
long double				check_left_side_walls(t_parse **cub_file, int i);

void					check_upper_side_sprites(t_parse **cub_file, int i);
void					check_lower_side_sprites(t_parse **cub_file, int i);
void					check_right_side_sprites(t_parse **cub_file, int i);
void					check_left_side_sprites(t_parse **cub_file, int i);

void					draw_upper_side_sprites(t_parse **cub_file, int i);
void					draw_lower_side_sprites(t_parse **cub_file, int i);
void					draw_left_side_sprites(t_parse **cub_file, int i);
void					draw_right_side_sprites(t_parse **cub_file, int i);
void					ft_draw_sprite(t_parse **cub_file, int n);

long double 			check_upper_side_n_sprite(t_parse **cub_file, int i, int n_sprite);
long double 			check_lower_side_n_sprite(t_parse **cub_file, int i, int n_sprite);
long double 			check_right_side_n_sprite(t_parse **cub_file, int i, int n_sprite);
long double 			check_left_side_n_sprite(t_parse **cub_file, int i, int n_sprite);

void				draw_map_2d(t_parse **cub_file, int x, int y);
void				draw_upper_side_walls(t_parse **cub_file);
void				draw_lower_side_walls(t_parse **cub_file);
void				draw_right_side_walls(t_parse **cub_file);
void				draw_left_side_walls(t_parse **cub_file);

int					move2d(t_parse **cub_file);
void				get_coordinate_of_player(t_parse **cub_file);
void				get_player_point_of_view(t_parse **cub_file);
void				work_with_cub_file(t_parse **cub_file, int argc, char **argv);
void				check_if_dot_cub(char *filename);
void				ft_define_scale(t_parse **cub_file);
int					key_hook(int keycode, t_parse **cub_file);
int					red_cross(t_parse **cub_file);

int					ray_cast(t_parse **cub_file);
int					ray_cast_sprites(t_parse **cub_file);
void				ft_screenshot(t_parse **cub_file, char *s1);
void				complete_data_sprites(t_parse **cub_file);
void 				draw_front_of_him(t_parse **cub_file, int n, int tmp_x);
int					check_if_sprite_is_drawn(t_parse **cub_file);
void				match_sprites_as_not_drawn(t_parse **cub_file);
void				get_height_sprite_from_center(t_parse **cub_file);
void				sort_sprites(t_parse **cub_file);
void 				remove_sprite_from_map2d(t_parse **cub_file);
char 				**ft_copy_map2d(char **map2d, t_parse **cub_file);
void 				ft_free_map2d(char **map2d, t_parse **cub_file);
char				check_sides_walls_for_raycsting(t_parse **cub_file);
void				check_sides_sprites_for_raycasting(t_parse **cub_file, int i);

// int					check_num_of_sprites(t_parse *cub_file);
int					get_stretched_width_of_sprite(t_parse **cub_file, int num_of_sprite, int tmp_x_nachalo);
int					arrange_sprites(t_parse **cub_file);
int					check_sprites(t_parse **cub_file, int i_scale, int n_sprite);
int					get_sprite(t_parse **cub_file, int tmp_x, int n_sprite, int i_scale);
int					get_end_sprite(long double FOV, int tmp_x, t_parse **cub_file, int i_scale);
int 				draw_sprite(t_parse **cub_file, int i);
int					get_n_sprite(t_parse **cub_file, int n_sprite);

void	            my_mlx_pixel_put(t_parse *data, int x, int y, int color);
int					get_textures(t_parse **cub_file);

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strjoin_3(char const *s1, char const *s2, char const *s3);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
void				ft_error(char *text);
#endif