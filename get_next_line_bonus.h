/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:37 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/17 09:50:09 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//macros

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef OPNENFD_MAX
#  define OPENFD_MAX 1024
# endif

//libraries

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//prototype functions

char	*get_next_line(int fd);
char	*join_buffer_to_line(char *buffer, char *line);
char	*shift_buffer_left(char *buffer);
int		search_buffer_linebreak(char *buffer);
int		get_len(char *string);

#endif