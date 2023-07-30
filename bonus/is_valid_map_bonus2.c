/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_bonus2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:35 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 15:38:51 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_unknown_element_bonus(t_game *game)
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
				&& ch != 'E' && ch != 'C' && ch != 'Q')
				ft_error_map(game, 'u');
			j++;
		}
		i++;
	}
}
