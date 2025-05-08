/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:37 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/08 21:31:03 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//macros

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//libraries

# include <unistd.h>
# include <stdlib.h>

//prototype functions

char	*get_next_line(int fd);

#endif