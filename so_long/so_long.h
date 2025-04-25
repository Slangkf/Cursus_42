/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/14 10:50:56 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <mlx.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

//Structure pour la gestion des images
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

//Structure pour la gestion du jeu
typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	char	**map;
	int		column;
	int		row;
	int		player_nb;
	int		exit_nb;
	int		coin_nb;
	int		move_nb;
	int		x_pos;
	int		y_pos;
}		t_game;

//main
int		main(int argc, char **argv);
int		ft_keyboard_manag(int keycode, t_game *game);
int		ft_close_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_exit_solong(t_game *game);
void	ft_load_images(t_game *game);
void	ft_load_wall_img(t_game *game);
void	ft_load_floor_img(t_game *game);
void	ft_load_player_img(t_game *game);
void	ft_load_exit_img(t_game *game);
void	ft_load_coin_img(t_game *game);
void	ft_display_map(t_game *game);

//parsing
int		ft_check_input(int argc, char **argv);
int		ft_check_map(t_game *game);
int		ft_is_good_char(t_game *game);
int		ft_is_rectangular(t_game *game);
int		ft_closed_walls(t_game *game);
int		ft_count_elements(t_game *game);
int		ft_check_map_path(t_game *game);

//utils
void	ft_print_error(char *message);
void	ft_free_map(char **map);
void	ft_free_struc(t_game *game);
void	ft_flood_fill(char **cloned_map, int x, int y);
void	ft_find_player_pos(char **cloned_map, t_game *game);
char	**ft_new_split(char const *s, char c, t_game *game);
char	**ft_map_clone(t_game *game);
int		ft_strrnchr(char *s1, char *s2, int len);
int		ft_read_map(char **map);

#endif
