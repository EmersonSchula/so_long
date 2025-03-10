/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:30:50 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:30:52 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (d_size <= d_len)
		return (d_size + s_len);
	i = d_len;
	while (*src && (i < d_size - 1))
		dest[i++] = *src++;
	dest[i] = '\0';
	return (d_len + s_len);
}
