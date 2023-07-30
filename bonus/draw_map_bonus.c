/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:18 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 11:42:35 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	draw_map_bonus_rest2(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.coin, j * 56, i * 56);
		game->para++;
	}
	else if (game->map.map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.exit, j * 56, i * 56);
	else if (game->map.map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.ch, j * 56, i * 56);
		game->pos.x = j * 56;
		game->pos.y = i * 56;
	}
	else if (game->map.map[i][j] == 'Q')
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.en, j * 56, i * 56);
	return (1);
}

int	draw_map_bonus_rest(t_game *game, int i, int j)
{
	int	height;
	int	width;

	height = game->map.height;
	width = game->map.width;
	if (game->map.map[i][j] == '1' && ((i == 0 || i == height - 1)
		|| (j == 0 || j == width - 1)))
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.wall, j * 56, i * 56);
	else if (game->map.map[i][j] == '1' && ((i != 0 && i != height - 1)
		&& (j != 0 && j != width - 1)))
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.wall2, j * 56, i * 56);
	else if (game->map.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->asset.path, j * 56, i * 56);
	else
		draw_map_bonus_rest2(game, i, j);
	return (1);
}

int	draw_map_bonus(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			draw_map_bonus_rest(game, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
