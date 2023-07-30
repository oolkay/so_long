/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:27 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 15:42:01 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_read(t_game *game)
{
	free(game->mlx);
	write (2, "Error\n", 6);
	write (2, "couldn't read map\n", 18);
	exit(1);
}

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

void	ft_error_asset(void)
{
	write (2, "Error\n", 6);
	write (2, "couldn't open an asset\n", 23);
	exit(1);
}

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
