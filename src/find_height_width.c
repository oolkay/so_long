/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_height_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:11 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/17 18:39:33 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_height_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i] != NULL)
		i++;
	game->map.height = i;
	game->map.width = ft_strlen(game->map.map[0]);
}
