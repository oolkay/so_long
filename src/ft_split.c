/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:19 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:54 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/// @brief Finds the length of the word
/// @param str The string to be searched
/// @param c Delimiter character
/// @return Length of the word
static int	wordslen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}


/// @brief Finds the number of words in the string
/// @param str The string to be searched
/// @param c Delimiter character
/// @return Word count
static int	wordsnbr(const char *str, char c)
{
	int		i;
	int		rvalue;

	i = 0;
	rvalue = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			rvalue++;
		i++;
	}
	return (rvalue);
}


/// @brief Splits the string according to the delimiter character
/// @param s String to be split
/// @param c Delimiter character
/// @return Splitted string
static char	*splitter(const char *s, char c)
{
	int		i;
	char	*resultstr;

	resultstr = (char *)malloc(sizeof(char) * (wordslen(s, c) + 1));
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		resultstr[i] = s[i];
		i++;
	}
	resultstr[i] = '\0';
	return (resultstr);
}


/// @brief Splits the string according to the delimiter character
/// @param s String to be split
/// @param c Delimiter character
/// @return Two-dimensional char array that contains splitted strings
char	**ft_split(const char *s, char c)
{
	char	**spltdstr;
	int		i;
	int		j;
	int		wcount;

	wcount = wordsnbr(s, c);
	spltdstr = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!spltdstr)
		return (0);
	i = 0;
	j = 0;
	while (i < wcount)
	{
		while (s[j] == c)
			j++;
		spltdstr[i] = splitter(s + j, c);
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	spltdstr[i] = 0;
	return (spltdstr);
}
