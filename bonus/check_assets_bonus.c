/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assets_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:57:02 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/24 11:52:37 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_assets_bonus_rest(void)
{
	int	fd;

	fd = open("./textures/en.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	fd = open("./textures/wall2.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
}

void	check_assets_bonus(void)
{
	int	fd;

	fd = open("./textures/c01.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	fd = open("./textures/c02.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	fd = open("./textures/path.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	fd = open("./textures/portal1.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	fd = open("./textures/wall.xpm", O_RDONLY);
	if (fd == -1)
		ft_error_asset();
	close(fd);
	check_assets_bonus_rest();
}
