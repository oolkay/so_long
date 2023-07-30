/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:25 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 15:40:58 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_int_arr(t_game *game, int **arr)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

void	free_char_arr(char **arr)
{
	char	**str;
	int		y;

	str = (char **)arr;
	y = 0;
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}
