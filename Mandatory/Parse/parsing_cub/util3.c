/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:26 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 03:06:29 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

t_map	*ft_get_line(int fd)
{
	t_map	*buffer;
	t_map	*tmp;
	t_map	*tmp1;

	(1) && (buffer = NULL, tmp = NULL, tmp1 = NULL);
	buffer = get_ptr(buffer, fd);
	if (!buffer)
		return (NULL);
	(1) && (buffer->next = NULL, tmp = buffer);
	while (1)
	{
		buffer->tmp = get_next_line(fd);
		if (!buffer->tmp)
			break ;
		tmp1 = (t_map *)malloc(sizeof(t_map));
		if (!tmp1)
			return (close(fd), ft_free_list(buffer), NULL);
		tmp1->s = ft_strdup_p(buffer->tmp);
		if (!tmp1->s)
			return (close(fd), ft_free_list(buffer), NULL);
		tmp->next = tmp1;
		(1) && (tmp1->next = NULL, tmp = tmp->next);
	}
	close(fd);
	return (buffer);
}

t_map	*ft_load_file_contenent(int ac, char **av)
{
	t_map	*buffer;
	int		fd;

	(1) && (fd = -1, buffer = NULL);
	fd = ft_cheek_fd(ac, av);
	if (fd == -1)
		return (NULL);
	buffer = ft_get_line(fd);
	if (!buffer)
		return (NULL);
	return (buffer);
}

int	ft_cheek_fd(int ac, char **av)
{
	int	fd;

	fd = -1;
	if (ac != 2)
	{
		ft_error1("Error\n->The correct usage");
		ft_error1(" is : ./cub3D <filename>.cub!\n");
		return (-1);
	}
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4) != 0)
		return (ft_error3("Error\n->The extintion of the file "\
		, av[1], " not valid!\n"), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error3("Error\n->Permission denied to open the file "\
		, av[1], " or the file not exist!\n"), -1);
	if (read(fd, NULL, 1) == 0)
		return (close(fd), ft_error1("Error\nEmpty file map\n"), -1);
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
		return (ft_error1("Error\ninvalid tex_path\n"), NULL);
	count = ft_strlen_m(buffer, ' ');
	s = malloc(count + 1);
	while (buffer[i] && i < count)
		s[j++] = buffer[i++];
	s[j] = '\0';
	return (s);
}
