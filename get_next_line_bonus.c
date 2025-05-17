/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/17 10:15:37 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPENFD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = join_buffer_to_line(buffer[fd], line);
	while (!search_buffer_linebreak(buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0 || buffer[fd][0] == 0)
		{
			shift_buffer_left(buffer[fd]);
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = join_buffer_to_line(buffer[fd], line);
	}
	shift_buffer_left(buffer[fd]);
	return (line);
}
/* 
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fda;
	int fdb;
	
	fda = open("a.txt", O_RDONLY);
	fdb = open("b.txt", O_RDONLY);
	printf("%s", get_next_line(fda));
	printf("%s", get_next_line(fdb));
	printf("%s", get_next_line(fda));
} */
