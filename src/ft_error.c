/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:15 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:50 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Prints error message and exits the program
/// @param game Game structure
void	ft_error_read(t_game *game)
{
	free(game->mlx);
	write (2, "Error\n", 6);
	write (2, "couldn't read map, empty map or contains only newline\n", 55);
	exit(1);
}

/// @brief Prints error message and exits the program
/// @param argc Number of arguments
void	ft_error_format(int argc)
{
	write (2, "Error\n", 6);
	if (argc == 1)
		write (2, "missing map\n", 12);
	else if (argc > 2)
		write (2, "extra arg\n", 10);
	else if (argc == -1)
		write (2, "invalid map format\n", 19);
	else
		write (2, "nonexisting map file\n", 21);
	exit(1);
}

/// @brief Prints error message and exits the program
void	ft_error_asset(void)
{
	write (2, "Error\n", 6);
	write (2, "couldn't open an asset\n", 23);
	exit(1);
}

/// @brief Prints error message and exits the program
/// @param game Game structure
/// @param c Error code
void	ft_error_map(t_game *game, char c)
{
	free(game->mlx);
	free_char_arr(game->map.map);
	write (2, "Error\n", 6);
	if (c == 'p')
		write (2, "invalid player\n", 15);
	else if (c == 'c')
		write (2, "no coin\n", 8);
	else if (c == 'e')
		write (2, "invalid exit\n", 13);
	else if (c == 's')
		write (2, "map isn't surrounded\n", 21);
	else if (c == 'r')
		write (2, "map isn't rectangular\n", 22);
	else if (c == 'm')
		write (2, "map is too small\n", 17);
	else if (c == 'u')
		write (2, "unknown map element\n", 20);
	else if (c == 'v')
		ft_putstr_fd("It is impossible to finish the game", 2);
	exit(1);
}
