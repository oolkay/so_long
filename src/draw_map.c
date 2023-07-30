/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:07 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:41 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Draws the map
/// @param game Game structure
/// @param i x coordinate
/// @param j y coordinate
void	draw_map_rest_2(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->asset.coin,
			j * 56, i * 56);
		game->para++;
	}
	else if (game->map.map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.exit,
			j * 56, i * 56);
	else if (game->map.map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->asset.ch,
			j * 56, i * 56);
		game->pos.x = j * 56;
		game->pos.y = i * 56;
	}
}

/// @brief Draws the map
/// @param game Game structure
/// @param i x coordinate
/// @param j y coordinate
void	draw_map_rest(t_game *game, int i, int j)
{
	int	height;
	int	width;

	height = game->map.height;
	width = game->map.width;
	if (game->map.map[i][j] == '1' && ((i == 0 || i == height - 1)
		|| (j == 0 || j == width - 1)))
		mlx_put_image_to_window(game->mlx, game->win, game->asset.wall,
			j * 56, i * 56);
	else if (game->map.map[i][j] == '1' && ((i != 0 && i != height - 1)
		&& (j != 0 && j != width - 1)))
		mlx_put_image_to_window(game->mlx, game->win, game->asset.wall2,
			j * 56, i * 56);
	else if (game->map.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.path,
			j * 56, i * 56);
	else
		draw_map_rest_2(game, i, j);
}

/// @brief Draws the map
/// @param game Game structure
void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			draw_map_rest(game, i, j);
			j++;
		}
		i++;
	}
}
