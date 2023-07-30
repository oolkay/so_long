/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:05 by acepni            #+#    #+#             */
/*   Updated: 2023/03/21 12:47:13 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*keep_remainder(char *arr)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (arr[i] != '\0' && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(arr) - i));
	if (!remainder)
		return (NULL);
	i++;
	j = 0;
	while (arr[i + j] != '\0')
	{
		remainder[j] = arr[j + i];
		j++;
	}
	remainder[j] = '\0';
	free(arr);
	return (remainder);
}

char	*trim_main_line(char *arr)
{
	int		i;
	char	*line;

	i = 0;
	if (!arr[i])
		return (NULL);
	while (arr[i] != '\0' && arr[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (arr[i] != '\0' && arr[i] != '\n')
	{
		line[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
	{
		line[i] = arr[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*readline(int fd, char *arr)
{
	char	*temp;
	int		r;

	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	r = 1;
	while (!ft_strchr(arr, '\n') && r != 0)
	{
		r = read(fd, temp, BUFFER_SIZE);
		if (r == -1)
		{
			free(temp);
			return (NULL);
		}			
		temp[r] = '\0';
		arr = ft_strjoin(arr, temp);
	}
	free(temp);
	return (arr);
}

char	*get_next_line(int fd)
{
	char		*mainline;
	static char	*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	arr = readline(fd, arr);
	if (!arr)
		return (NULL);
	mainline = trim_main_line(arr);
	arr = keep_remainder(arr);
	return (mainline);
}
