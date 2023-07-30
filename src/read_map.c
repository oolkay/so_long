/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:33 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/23 17:43:02 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	split_map(t_game *game, char *line)
{
	game->map.map = ft_split(line, '\n');
	if (!game->map.map)
	{
		ft_error_read(game);
	}
}

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
