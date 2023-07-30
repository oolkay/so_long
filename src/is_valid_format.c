/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:21 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:56 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Checks whether the game executed with valid arguments
/// @param argc Argument count
/// @param argv Argument vector
void	is_valid_format(int argc, char **argv)
{
	int	fd;
	int	len;

	if (argc != 2)
		ft_error_format(argc);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
			|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		ft_error_format(-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error_format(-2);
	close(fd);
}
