/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:24:41 by eschula           #+#    #+#             */
/*   Updated: 2025/03/10 16:24:44 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../../libft.h"

# include <stdlib.h>
# include <unistd.h>

// get the next line from specified file descriptor
char	*get_next_line(int fd);
char	*get_nl_address(const char *s);
char	*ft_strjoin_with_free(char *s1, char *s2);

// Returns the static buffer of GNL
char	**get_gnl_buffer(void);

// Closes the file descriptor and clears its associated static buffer
void	close_and_clear(int fd);

#endif
