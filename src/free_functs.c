/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:13 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:48 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Free two-dimensional int array
/// @param game Game structure
/// @param arr two-dimensional int array
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

/// @brief Free two-dimensional char array
/// @param arr Two-dimensional char array
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
