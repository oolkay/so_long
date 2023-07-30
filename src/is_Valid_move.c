/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_Valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:28 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:52:02 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/// @brief Checks if the move is valid on x direction	
/// @param ch Keycode
/// @param game Game structure
/// @return 1 on valid move, 0 on invalid move
int	is_valid_move_x(char ch, t_game *game)
{
	if (ch == A)
	{
		if (game->map.map[game->pos.y / 56][game->pos.x / 56 - 1] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56][game->pos.x / 56 - 1] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
	}
	if (ch == D)
	{
		if (game->map.map[game->pos.y / 56][game->pos.x / 56 + 1] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56][game->pos.x / 56 + 1] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
	}
	return (1);
}

/// @brief Checks if the move is valid on y direction
/// @param ch Keycode
/// @param game Game structure
/// @return 1 on valid move, 0 on invalid move
int	is_valid_move_y(char ch, t_game *game)
{
	if (ch == W)
	{
		if (game->map.map[game->pos.y / 56 - 1][game->pos.x / 56] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56 - 1][game->pos.x / 56] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
	}
	else if (ch == S)
	{
		if (game->map.map[game->pos.y / 56 + 1][game->pos.x / 56] == '1')
			return (0);
		else if (game->map.map[game->pos.y / 56 + 1][game->pos.x / 56] == 'E'
			&& is_exit_open(game) == 0)
			return (0);
	}
	return (1);
}
