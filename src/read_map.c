/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:33 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:52:06 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Splits the map into a two-dimensional char array
/// @param game Game structure
/// @param line Single line read from the xpm file
void	split_map(t_game *game, char *line)
{
	game->map.map = ft_split(line, '\n');
	if (!game->map.map)
	{
		ft_error_read(game);
	}
}

/// @brief Reads the map from the xpm file
/// @param game Game structure
/// @param argv Argument vector
void	read_map(t_game *game, char **argv)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	temp = get_next_line(fd);
	if (!temp || !fd)
		ft_error_read(game);
	while (ft_strchr(temp, '\n'))
	{
		line = ft_strjoin(line, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	if (temp)
		line = ft_strjoin(line, temp);
	split_map(game, line);
	free(line);
	free(temp);
	close(fd);
}
