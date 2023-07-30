/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:26 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:52:00 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/// @brief Checks if the map is surrounded by walls
/// @param game Game structure
void	is_surrounded_map(t_game *game)
{
	int	height;
	int	width;
	int	i;

	i = 0;
	height = game->map.height;
	width = game->map.width;
	while (i < width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[height - 1][i] != '1')
			ft_error_map(game, 's');
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][width - 1] != '1')
			ft_error_map(game, 's');
		i++;
	}
}

/// @brief Checks elements of the map
/// @param game Game structure
/// @param p Player counter
/// @param e Exit counter
void	check_elements_map_rest(t_game *game, int p, int e)
{
	int	height;
	int	width;

	height = game->map.height;
	while (--height >= 0)
	{
		width = game->map.width;
		while (--width >= 0)
		{
			if (game->map.map[height][width] == 'P')
				p++;
			else if (game->map.map[height][width] == 'C')
				game->para++;
			else if (game->map.map[height][width] == 'E')
				e++;
		}
	}
	if (p != 1)
		ft_error_map(game, 'p');
	if (game->para < 1)
		ft_error_map(game, 'c');
	if (e != 1)
		ft_error_map(game, 'e');
}

/// @brief Checks the elements of the map
void	check_elements_map(t_game *game)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	check_elements_map_rest(game, p, e);
}

/// @brief Checks the map is rectangular
/// @param game Game structure
void	is_rectangular_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height - 1)
	{
		if (ft_strlen(game->map.map[i]) != ft_strlen(game->map.map[i + 1]))
			ft_error_map(game, 'r');
		i++;
	}
}

/// @brief Checks the map is valid
/// @param game Game structure
void	is_valid_map(t_game *game)
{
	is_surrounded_map(game);
	check_elements_map(game);
	is_rectangular_map(game);
	is_unknown_element(game);
	if (path_checker(game) == 0)
		ft_error_map(game, 0);
}
