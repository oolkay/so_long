/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:09 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/17 18:39:10 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}

void	did_player_move(t_game *game, int n, int flag_y, int flag_x)
{
	if ((n == W || n == S) && flag_y == 1)
	{
		ft_putstr_fd("current move : ", 1);
		ft_putnbr_fd(++game->movecount, 1);
		ft_putchar_fd('\n', 1);
	}
	else if ((n == A || n == D) && flag_x == 1)
	{
		ft_putstr_fd("current move : ", 1);
		ft_putnbr_fd(++game->movecount, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	key_events(int keycode, t_game *game)
{
	int	flag_y;
	int	flag_x;

	flag_y = is_valid_move_y(keycode, game);
	flag_x = is_valid_move_x(keycode, game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->asset.path, game->pos.x, game->pos.y);
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
	mlx_put_image_to_window(game->mlx, game->win,
		game->asset.ch, game->pos.x, game->pos.y);
	if (game->map.map[game->pos.y / 56][game->pos.x / 56] == 'C'
		|| game->map.map[game->pos.y / 56][game->pos.x / 56] == 'E')
		special_events(game->map.map[game->pos.y / 56][game->pos.x / 56], game);
	did_player_move(game, keycode, flag_y, flag_x);
	return (0);
}
