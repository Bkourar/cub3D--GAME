/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:51:31 by eenassir          #+#    #+#             */
/*   Updated: 2024/03/18 11:23:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(int fd, char *save)
{
	char	*buffer;
	ssize_t	byte;

	byte = 1;
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (byte && !ft_strchr(save, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[byte] = '\0';
		save = f(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*getx_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	if (save[0] == '\0')
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_rest(char *save)
{
	char	*rest;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (save[k] && save[k] != '\n')
		k++;
	if (save[k] == '\n')
		k++;
	else
		return (free(save), NULL);
	i = k;
	while (save[i++])
		j++;
	rest = (char *)malloc(j + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (save[k])
		rest[j++] = save[k++];
	rest[j] = '\0';
	free(save);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = get_read(fd, save);
	if (!save)
		return (NULL);
	line = getx_line(save);
	save = get_rest(save);
	return (line);
}
