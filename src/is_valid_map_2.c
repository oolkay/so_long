/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:23 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:58 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Checks whether the map contains unknown elements
/// @param game Game structure
void	is_unknown_element(t_game *game)
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	find_height_width(game);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			ch = game->map.map[i][j];
			if (ch != '1' && ch != '0' && ch != 'P'
				&& ch != 'E' && ch != 'C')
				ft_error_map(game, 'u');
			j++;
		}
		i++;
	}
}
