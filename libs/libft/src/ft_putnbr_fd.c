/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:29:34 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:29:36 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		divisor;
	long	nlong;
	char	c;

	nlong = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nlong = -nlong;
	}
	divisor = 1;
	while (nlong / divisor >= 10)
		divisor *= 10;
	while (divisor)
	{
		c = (nlong / divisor) + '0';
		write(fd, &c, 1);
		nlong %= divisor;
		divisor /= 10;
	}
}
