/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closegame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:27:38 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:37 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Closing game scenarios: win, lose, die
/// @param game The game structure
/// @param ch The character that represents the scenario
int	close_game(t_game *game, char ch)
{
	mlx_destroy_image(game->mlx, game->asset.ch);
	mlx_destroy_image(game->mlx, game->asset.wall);
	mlx_destroy_image(game->mlx, game->asset.wall2);
	mlx_destroy_image(game->mlx, game->asset.exit);
	mlx_destroy_image(game->mlx, game->asset.coin);
	free_char_arr(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	if (ch == 'W')
	{
		ft_putstr_fd("COINS WERE COLLECTED, THE EXIT WAS REACHED\n", 1);
		ft_putstr_fd("CONGRATS!, YOU WIN\n", 1);
	}
	else if (ch == 'L')
		ft_putstr_fd("THE GAME WAS TERMINATED BY USER WITHOUT ANY ERROR\n", 1);
	else if (ch == 'E')
		ft_putstr_fd("YOU DIED\n", 1);
	exit (0);
}

/// @brief Closing game when the user clicks the red cross
/// @param game The game structure
int	close_game_mouse(t_game *game)
{
	mlx_destroy_image(game->mlx, game->asset.ch);
	mlx_destroy_image(game->mlx, game->asset.wall);
	mlx_destroy_image(game->mlx, game->asset.wall2);
	mlx_destroy_image(game->mlx, game->asset.exit);
	mlx_destroy_image(game->mlx, game->asset.coin);
	free_char_arr(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	ft_putstr_fd("THE GAME WAS TERMINATED BY USER WITHOUT ANY ERROR\n", 1);
	exit (0);
}
