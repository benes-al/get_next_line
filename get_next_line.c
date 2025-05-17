/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/17 09:54:45 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = join_buffer_to_line(buffer, line);
	while (!search_buffer_linebreak(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || buffer[0] == 0)
		{
			shift_buffer_left(buffer);
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = join_buffer_to_line(buffer, line);
	}
	shift_buffer_left(buffer);
	return (line);
}
/* 
#include <fcntl.h>
#include <stdio.h>

int	main (void)
{
	int	fd;
	char *str;
	//char *str1;
	//char *str2;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	//str1 = get_next_line(fd);
	//str2 = get_next_line(fd);
	printf("%s", str);
	//printf("%s", str1);
	//printf("%s", str2);
	free(str);
	//free(str1);
	//free(str2);
	close(fd);
	printf("%s", get_next_line(0));
} */