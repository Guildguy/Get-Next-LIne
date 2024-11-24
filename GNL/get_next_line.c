/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:33:23 by fleite-j          #+#    #+#             */
/*   Updated: 2024/11/20 18:33:37 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line_buffer(int fd, char *remaining_data, char *buffer)
{
	ssize_t	bytes_read;
	char	*temporary_buffer;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remaining_data);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remaining_data)
			remaining_data = ft_strdup("");
		temporary_buffer = remaining_data;
		remaining_data = ft_strjoin(temporary_buffer, buffer);
		free(temporary_buffer);
		temporary_buffer = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remaining_data);
}

static char	*ft_set_line(char *line_buffer)
{
	char	*remaining_data;
	ssize_t	index;

	index = 0;
	while (line_buffer[index] != '\0' || line_buffer[index] != '\n')
		index++;
	if (line_buffer[index] == 0 || line_buffer[1] == 0)
		return (NULL);
	remaining_data = ft_substr(line_buffer, index + 1, ft_strlen(line_buffer) - index);
	if (remaining_data == 0)
	{
		free(remaining_data);
		remaining_data = NULL;
	}
	line_buffer[index + 1] = '\0';

	return (remaining_data);
}

char	*get_next_line(int fd)
{
	static char	*remaining_buffer;
	char	*line;
	char	*buffer;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		free(remaining_buffer);
		free(buffer);
		remaining_buffer = NULL;
		buffer = (NULL);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_fill_line_buffer(fd, remaining_buffer, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remaining_buffer = ft_set_line(line);
	return (line);
}
