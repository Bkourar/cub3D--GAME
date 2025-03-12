/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 18:18:33 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

int	ft_cheek_fd(int ac, char **av)
{
	int	fd;

	fd = -1;
	if (ac != 2)
		return (ft_error(NULL, "Error\n", \
		"->The correct usage is : ./cub3D <filename>.cub!\n"), -1);
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4) != 0)
		return (ft_error("Error\n->The extintion of the file "\
		, av[1], " not valid!\n"), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Error\n->Permission denied to open the file "\
		, av[1], " or the file not exist!\n"), -1);
	if (read(fd, NULL, 1) == 0)
		return (close(fd), ft_error(NULL, NULL, "Error\nEmpty file map\n"), -1);
	return (fd);
}

char	*ft_re_alloc(char *buffer)
{
	int		count;
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	if (buffer[0] == '.')
		i++;
	while (buffer[i] && buffer[i] == '/')
		i++;
	if (buffer[i] == '\0')
		return (ft_error(NULL, NULL, "Error\ninvalid tex_path\n"), NULL);
	count = ft_strlen_m(buffer, ' ');
	s = malloc(count + 1);
	while (buffer[i] && i < count)
		s[j++] = buffer[i++];
	s[j] = '\0';
	return (s);
}
