/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:27:58 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/15 19:46:01 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*shift_buffer_left(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
	return (buffer);
}

char	*join_buffer_to_line(char *buffer, char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * (get_len(line) + get_len(buffer) + 1));
	if (!new_line)
		return (free (line), NULL);
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i + j < (get_len(line) + get_len(buffer)))
	{
		new_line[i + j] = buffer[j];
		j++;
	}
	new_line[i + j] = '\0';
	if (line)
		free(line);
	if (!new_line)
		return (free(new_line), NULL);
	return (new_line);
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

int	get_len(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}
