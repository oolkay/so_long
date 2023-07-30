/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:16 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 12:00:12 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_image(t_game *game)
{
	game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c01.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.wall2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall2.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.coin = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/portal1.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.path = mlx_xpm_file_to_image(game->mlx, "./textures/path.xpm",
			&game->asset.aht, &game->asset.awt);
	game->asset.en = mlx_xpm_file_to_image(game->mlx, "./textures/en.xpm",
			&game->asset.aht, &game->asset.awt);
}
