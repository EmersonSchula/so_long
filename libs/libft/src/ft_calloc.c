/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:26:38 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:26:41 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*allocd_mem;

	allocd_mem = (void *)malloc(n * size);
	if (allocd_mem == NULL)
		return (NULL);
	ft_bzero(allocd_mem, n * size);
	return (allocd_mem);
}
