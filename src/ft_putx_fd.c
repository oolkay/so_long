/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <o.olkay2021@gtu.edu.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:28:17 by oolkay            #+#    #+#             */
/*   Updated: 2023/07/30 14:51:52 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief Print integer to file descriptor
/// @param n Number to print
/// @param fd File descriptor
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

/// @brief Print string to file descriptor
/// @param s String to print
/// @param fd File descriptor
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

/// @brief Print character to file descriptor
/// @param c Character to print
/// @param fd File descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
