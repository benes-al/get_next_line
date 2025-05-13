/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:58 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/12 18:46:00 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*shift_buffer_left(char *buffer)
{
	while (*buffer != '\n')
		buffer++;
	return (buffer);
}

char	*join_buffer_to_line(char *buffer, char *line)
{
	char	*temp;
	int		temp_bytes;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp_bytes = get_string_lenght(line) + get_string_lenght(buffer);
	temp = malloc(sizeof(char) * (temp_bytes + 1));
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

int	search_buffer_linebreak(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_string_lenght(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
	
}
