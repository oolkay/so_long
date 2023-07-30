/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:30 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:52:04 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Inıtializes the int array
/// @param game Game structure
/// @return Two-dimensional int array that contains visited coordinates
int	**memory_arr(t_game game)
{
	int	x;
	int	y;
	int	**vstd;

	x = 0;
	y = -1;
	vstd = (int **)malloc(sizeof(int *) * game.map.height);
	if (!vstd)
		return (0);
	while (++y < game.map.height)
	{
		vstd[y] = (int *)malloc(sizeof(int) * game.map.width);
		if (!vstd[y])
			return (0);
	}
	y = -1;
	while (++y < game.map.height)
	{
		x = -1;
		while (++x < game.map.width)
			vstd[y][x] = 0;
	}
	return (vstd);
}

/// @brief Finds the player's coordinates
/// @param game Game structure
/// @param x x coordinate
/// @param y y coordinate
void	find_player(t_game game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			if (game.map.map[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

/// @brief Graph search algorithm
/// @param game Game structure
/// @param i X coordinate
/// @param j Y coordinate
/// @param vstd The int array contains the visited coordinates
/// @return 1 on success, otherwise 0
int	is_valid_path(t_game *game, int i, int j, int **vstd)
{
	if (i < 0 || j < 0
		|| game->map.height <= i || game->map.width <= j || vstd[i][j] == 1)
		return (0);
	if (game->map.map[i][j] == 'E')
		game->map.path = 1;
	if (game->map.map[i][j] == 'C')
		game->para--;
	if ((game->map.map[i][j] == '0' || game->map.map[i][j] == 'C'
		|| game->map.map[i][j] == 'P') && vstd[i][j] == 0)
	{
		vstd[i][j] = 1;
		if (is_valid_path(game, i, j + 1, vstd))
			return (1);
		if (is_valid_path(game, i + 1, j, vstd))
			return (1);
		if (is_valid_path(game, i - 1, j, vstd))
			return (1);
		if (is_valid_path(game, i, j - 1, vstd))
			return (1);
	}
	return (0);
}

/// @brief Checks the map is finishable 
/// @param game Game structure
/// @return 1 if the map is finishable, otherwise 0
int	path_checker(t_game *game)
{
	int	x;
	int	y;
	int	**vstd;

	vstd = memory_arr(*game);
	if (!vstd)
		return (0);
	find_player(*game, &x, &y);
	is_valid_path(game, x, y, vstd);
	free_int_arr(game, vstd);
	if (game->map.path == 0 || game->para != 0)
		ft_error_map(game, 'v');
	return (1);
}
