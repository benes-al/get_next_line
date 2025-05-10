/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/10 08:36:19 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	while (ft_verification(buffer) =! 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		line = strcnt(line, buffer, bytes_read);
	} 
}

#include <fcntl.h>

int	main (void)
{
	int	fd;
	char *str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	free(str);
}