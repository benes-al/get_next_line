/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/08 21:31:03 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	while (verification(buffer) =! 1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		line = strcnt(line, buffer, bytes_read);
	} 
} */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
	
}

char	*ft_strcat(char *buffer, char *line, int bytes_read)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * (bytes_read + ft_strlen(line) + 1));
	if(!temp)
		return (0);
	while (line[i])
	{
		temp[i] = line[i];
		i++;
	}
	while (j < bytes_read && buffer[j])
	{
		temp[i + j] = buffer[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}

/* 
#include <fcntl.h>

int	main (void)
{
	int	fd;
	char *str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	free(str);
} */

int	main(void)
{
	printf("%s", ft_strcat("mento", "casa", 5));
}