/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:13 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/20 19:25:27 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		y;

	y = 0;
	while (arr[y] != 0)
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}
