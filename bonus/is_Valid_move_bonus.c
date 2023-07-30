/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Valid_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:39 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 12:24:16 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_move_x(char ch, t_game *game)
{
	if (ch == A)
	{
		if (game->map.map[game->pos.y / 56][game->pos.x / 56 - 1] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56][game->pos.x / 56 - 1] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
		mlx_destroy_image(game->mlx, game->asset.ch);
		game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c02.xpm",
				&game->asset.aht, &game->asset.awt);
	}
	if (ch == D)
	{
		if (game->map.map[game->pos.y / 56][game->pos.x / 56 + 1] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56][game->pos.x / 56 + 1] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
		mlx_destroy_image(game->mlx, game->asset.ch);
		game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c01.xpm",
				&game->asset.aht, &game->asset.awt);
	}
	return (1);
}

int	is_valid_move_y(char ch, t_game *game)
{
	if (ch == W)
	{
		if (game->map.map[game->pos.y / 56 - 1][game->pos.x / 56] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56 - 1][game->pos.x / 56] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
		mlx_destroy_image(game->mlx, game->asset.ch);
		game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c02.xpm",
				&game->asset.aht, &game->asset.awt);
	}
	else if (ch == S)
	{
		if (game->map.map[game->pos.y / 56 + 1][game->pos.x / 56] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56 + 1][game->pos.x / 56] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
		mlx_destroy_image(game->mlx, game->asset.ch);
		game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c01.xpm",
				&game->asset.aht, &game->asset.awt);
	}
	return (1);
}
