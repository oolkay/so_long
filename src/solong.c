/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:38 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 17:06:41 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	is_valid_format(argc, argv);
	check_assets();
	game.mlx = mlx_init();
	game.para = 0;
	game.effect = 0;
	game.movecount = 0;
	game.map.path = 0;
	game.map.height = 0;
	game.map.width = 0;
	read_map(&game, argv);
	find_height_width(&game);
	is_valid_map(&game);
	create_image(&game);
	game.win = mlx_new_window(game.mlx, game.map.width * 56,
			game.map.height * 56, "solong");
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, &key_events, &game);
	mlx_hook(game.win, 17, 0, &close_game_mouse, &game);
	mlx_loop(game.mlx);
}
