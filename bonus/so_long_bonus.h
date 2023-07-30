/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:45 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 17:08:04 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		path;
}t_map;

typedef struct s_asset
{
	void	*ch;
	void	*en;
	void	*wall;
	void	*wall2;
	void	*coin;
	void	*path;
	void	*exit;
	int		aht;
	int		awt;
}t_asset;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_pos	pos;
	t_asset	asset;
	t_map	map;
	int		para;
	int		effect;
	int		x;
	int		y;
	int		movecount;
}t_game;

void	create_image(t_game *game);
int		mouse_events(int buttoncode, t_game *game);
int		key_events(int keycode, t_game *game);
int		is_valid_move_x(char ch, t_game *game);
int		is_valid_move_y(char ch, t_game *game);
int		is_exit_open(t_game *game);
int		sprite(t_game *game);
int		close_game(t_game *game, char ch);
void	read_map(t_game *game, char **argv);
int		draw_map_bonus(t_game *game);
void	split_map(t_game *game, char *line);
void	ft_error(t_game *game);
void	ft_error_map(t_game *game, char c);
void	ft_error_format(int argc);
void	ft_error_read(t_game *game);
void	ft_error_asset(void);
char	**ft_split(const char *s, char c);
void	check_assets(void);
void	check_assets_bonus(void);
void	find_height_width(t_game *game);
void	is_valid_map_bonus(t_game *game);
int		path_checker(t_game *game);
void	is_valid_format(int argc, char **argv);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	free_char_arr(char **arr);
void	free_int_arr(t_game *game, int **arr);
void	find_ex(t_game *game, int *x, int *y);
void	find_en(t_game *game, int *x, int *y);
int		sprite(t_game *game);
void	is_unknown_element_bonus(t_game *game);
char	*ft_itoa(int nbr);
int		close_game_mouse(t_game *game);

#endif
