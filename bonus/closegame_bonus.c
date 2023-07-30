/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closegame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:14 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 12:24:58 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	exit(0);
}

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
