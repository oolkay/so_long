/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:27:04 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 11:50:34 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
