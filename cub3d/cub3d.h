/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:12:17 by tclouet           #+#    #+#             */
/*   Updated: 2025/09/23 16:30:41 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "include/libft/libft.h"
# include "include/minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <unistd.h>

# define WIDTH 1080
# define HEIGHT 720
# define MOVE_SPEED 0.3
# define ROT_SPEED 0.1

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_data		t_data;
typedef struct s_content	t_content;
typedef struct s_player		t_player;

typedef struct s_content
{
	char					**scene;
	char					**map;
	size_t					width;
	int						height;
	int						scene_height;
	int						nb_player;
	int						nb_id;
	int						texture_check;
	char					*no_wall_path;
	char					*so_wall_path;
	char					*ea_wall_path;
	char					*we_wall_path;
	char					**floor_range;
	char					**ceiling_range;
}							t_content;

typedef struct s_ray
{
	double					dir_x;
	double					dir_y;
	int						map_x;
	int						map_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
}							t_ray;

typedef struct s_player
{
	char					orientation;
	double					x_pos;
	double					y_pos;
	double					x_dir;
	double					y_dir;
}							t_player;

typedef struct s_tex
{
	void					*img;
	char					*addr;
	int						width;
	int						height;
	int						bpp;
	int						line_len;
	int						endian;
}							t_tex;

typedef struct s_wall_calc
{
	int						line_height;
	int						draw_start;
	int						draw_end;
	int						tex_x;
	t_tex					current_tex;
}							t_wall_calc;

typedef struct s_keys
{
	int						w;
	int						a;
	int						s;
	int						d;
	int						left;
	int						right;
}							t_keys;

typedef struct s_data
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	t_tex					north;
	t_tex					south;
	t_tex					east;
	t_tex					west;
	void					*floor;
	void					*ceiling;
	int						floor_color;
	int						ceiling_color;
	t_player				*player;
	t_keys					keys;
	t_content				*content;
}							t_data;

// init structures
t_data						*ft_init_structures(void);

// init game
void						ft_load_textures(t_data *data);
void						ft_load_floor(t_data *data);
void						ft_load_ceiling(t_data *data);
int							ft_close_game(t_data *data);

// parsing
void						ft_parser(int argc, char *argv, t_data *data);
int							ft_check_textures(char *line, t_data *data);
int							ft_check_id(char *line, char id, t_data *data);
int							ft_check_path(char *line, char id, t_data *data);
int							ft_check_range(char *line, char id, t_data *data);
int							ft_check_map(t_data *data);
int							ft_check_walls(t_data *data);

// parsing utils
int							ft_strrnchr(char *s1, char *s2, int len);
int							ft_is_player(char c);
void						ft_get_max_length(t_data *data, char **map);

// cleaning utils
void						ft_close_fd(void);
void						ft_free_double_array(char **array);
void						ft_print_error_exit(char *mess);
void						ft_print_error(char *mess);
void						ft_destroy_mlx(t_data *data);
void						ft_free_structures(t_data *data);

// raycasting
int							get_map_width(char **map);
int							get_map_height(char **map);
void						display_game(t_data *data);
void						dda_algo(t_data *data, t_ray *ray);
int							handle_key(int keycode, t_data *data);
void						init_ray(t_data *data, t_ray *ray, int x);
void						draw_wall_column(t_data *data, int x, t_ray *ray);
void						calculate_wall_distance(t_data *data, t_ray *ray);
int							update(t_data *data);
int							key_press(int keycode, t_data *data);
int							key_release(int keycode, t_data *data);
void						strafe_left(t_data *data, int map_width,
								int map_height);
void						strafe_right(t_data *data, int map_width,
								int map_height);
void						move_forward(t_data *data, int map_width,
								int map_height);
void						move_backward(t_data *data, int map_width,
								int map_height);
void						rotate_left(t_data *data);
void						rotate_right(t_data *data);

#endif
