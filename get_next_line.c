/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/12 19:50:39 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	buffer[BUFFER_SIZE + 1];

	line = "\0";
	temp = NULL;
	read(fd, buffer, BUFFER_SIZE);
	while (search_buffer_linebreak(buffer) != 1)
	{
		temp = line;
		line = join_buffer_to_line(buffer, line);
		free (temp);
		read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main (void)
{
	int	fd;
	char *str;
	
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
}