/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:20 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 11:43:56 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_exit_open(t_game *game)
{
	if (game->para != 0)
		return (0);
	return (1);
}

int	special_events(char ch, t_game *game)
{
	if (ch == 'C')
	{
		game->para--;
		game->map.map[game->pos.y / 56][game->pos.x / 56] = '0';
	}
	else if (ch == 'E' && is_exit_open(game))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->asset.ch,
			game->pos.x, game->pos.y);
		close_game(game, 'W');
	}
	else
		close_game(game, 'E');
	return (0);
}

void	did_player_move(t_game *game, int n, int flag_y, int flag_x)
{
	char	*str;

	mlx_put_image_to_window(game->mlx, game->win, game->asset.wall,
		0, 0);
	if (((n == W || n == S) && flag_y == 1)
		|| ((n == A || n == D) && flag_x == 1))
		game->movecount++;
	str = ft_itoa(game->movecount);
	mlx_string_put(game->mlx, game->win, 25, 30, 0xFFFFFFFF, str);
	if (str)
		free(str);
}

int	key_events(int keycode, t_game *game)
{
	int		flag_y;
	int		flag_x;
	char	ch;

	flag_y = is_valid_move_y(keycode, game);
	flag_x = is_valid_move_x(keycode, game);
	mlx_put_image_to_window(game->mlx, game->win, game->asset.path,
		game->pos.x, game->pos.y);
	if (keycode == W && flag_y == 1)
		game->pos.y -= 56;
	if (keycode == S && flag_y == 1)
		game->pos.y += 56;
	if (keycode == A && flag_x == 1)
		game->pos.x -= 56;
	if (keycode == D && flag_x == 1)
		game->pos.x += 56;
	if (keycode == ESC)
		close_game(game, 'L');
	mlx_put_image_to_window(game->mlx, game->win, game->asset.ch,
		game->pos.x, game->pos.y);
	ch = game->map.map[game->pos.y / 56][game->pos.x / 56];
	if (ch == 'C' || ch == 'E' || ch == 'Q')
		special_events(ch, game);
	did_player_move(game, keycode, flag_y, flag_x);
	return (0);
}
