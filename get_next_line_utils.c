/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:58 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/10 08:36:11 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (buffer[j])
	{
		temp[i + j] = buffer[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}

int	ft_verification(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer [i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
	
}