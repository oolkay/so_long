/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:27:04 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:33 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/// @brief Check if the assets are present
void	check_assets_rest(void)
{
	int	fd;

	fd = open("./textures/coin.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	fd = open("./textures/wall2.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	fd = open("./textures/path.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
}

/// @brief Check if the assets are present
void	check_assets(void)
{
	int	fd;

	fd = open("./textures/c01.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	fd = open("./textures/portal1.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	fd = open("./textures/wall.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	check_assets_rest();
	close(fd);
}
