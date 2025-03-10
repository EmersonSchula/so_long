/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:23 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:23:26 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>

// MACROS
# define DECI_BASE "0123456789"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA_LOW "0123456789abcdef"

// Print a string with specified format to a file descriptor
int		ft_printf_fd(int fd, const char *format, ...);

size_t	ft_putchar_fd(int fd, char c);
size_t	ft_putstr_fd(int fd, char *str);
size_t	ft_putptr_fd(int fd, unsigned long number, char *base);
size_t	ft_putnbr_base_fd(int fd, long int number, char *base);

#endif
