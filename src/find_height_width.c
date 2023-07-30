/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_height_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:11 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:45 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Finds the height and width of the map
/// @param game Game structure
void	find_height_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i] != NULL)
		i++;
	game->map.height = i;
	game->map.width = ft_strlen(game->map.map[0]);
}
