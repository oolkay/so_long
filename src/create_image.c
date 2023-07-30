/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:04 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:39 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Create the images
/// @param game The game structure
void	create_image(t_game *game)
{
	game->asset.ch = mlx_xpm_file_to_image(game->mlx, "./textures/c01.xpm",
			&game->asset.chht, &game->asset.chwt);
	game->asset.wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->asset.wht, &game->asset.wwt);
	game->asset.wall2 = mlx_xpm_file_to_image(game->mlx, "./textures/wall2.xpm",
			&game->asset.wht, &game->asset.wwt);
	game->asset.coin = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&game->asset.cht, &game->asset.cwt);
	game->asset.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/portal1.xpm",
			&game->asset.eht, &game->asset.ewt);
	game->asset.path = mlx_xpm_file_to_image(game->mlx, "./textures/path.xpm",
			&game->asset.pht, &game->asset.pwt);
}
