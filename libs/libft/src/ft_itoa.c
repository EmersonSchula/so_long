/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:54 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:27:56 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static size_t	count_char(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nlong;
	size_t	digits;
	int		negative;
	char	*str;

	negative = is_negative(n);
	nlong = (long)n;
	if (negative == 1)
		nlong = -nlong;
	digits = count_char(nlong);
	str = (char *)malloc(negative + digits + 1);
	if (str == NULL)
		return (NULL);
	if (negative == 1)
		str[0] = '-';
	str[digits + negative] = '\0';
	while (digits > 0)
	{
		str[(digits - 1) + negative] = (nlong % 10) + '0';
		nlong /= 10;
		digits--;
	}
	return (str);
}
