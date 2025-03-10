/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:44 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:22:47 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_check_format(char c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	len;
	size_t	i;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_check_format(format[i], args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return ((int)len);
}

static size_t	ft_check_format(char c, va_list args)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, unsigned long), HEXA_LOW);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(args, int), DECIMAL_BASE);
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), DECIMAL_BASE);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), HEXA_LOW);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), HEXA_UP);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
