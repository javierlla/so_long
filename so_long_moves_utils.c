/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:42 by jllarena          #+#    #+#             */
/*   Updated: 2024/01/29 16:52:43 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		write(fd, &s[i], 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			write(fd, "-", 1);
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_change_exit2(char *x, char *y)
{
	*x = 'E';
	*y = 'P';
}

void	ft_change_img(char *x, char *y)
{
	*x = '0';
	*y = 'P';
}
