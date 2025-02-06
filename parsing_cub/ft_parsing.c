#include "../recast.h"

char *ft_strdup_p(char *s)
{
	int i;
	char *p;
	
	if (s == NULL)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *ft_skip_spaces(char *s)
{
	int j = 0;	
	int i = 0;


	while (s[j] && s[j] == ' ')
		j++;
	return (s + j);
}

char *ft_strjoin_m(char *s1, int add)
{
	int i = 0;
	int j = 0;
	char *p;
	int some = 0;

	if (add == 0)
		return (s1);
	some = ft_strlen(s1) + add;
	p = malloc(some + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (i < some)
	{
		p[i] = ' ';
		i++;
	}
	p[i] = '\0';
	return (free(s1), p);
}

void ft_util1(char **array)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int max = 0;

	while (array[i])
	{
		count = ft_strlen(array[i]);
		(max < count) && (max = count);
			i++;
	}

	i = 0;
	int skip_sp = 0;
	int k = 0;
	while (array[i])
	{
		if (ft_strlen(array[i]) < max)
			array[i] = ft_strjoin_m(array[i], (max - ft_strlen(array[i])));
		i++;
	}
}

int ft_strlen_m(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		(s[i] != c) && (count++);
		i++;
	}
	return (count);
}

char *ft_re_alloc(char *buffer)
{
	int count = 0;
	char *s;
	int i = 0;
	int j = 0;

	count = ft_strlen_m(buffer, ' ');
	s = malloc(count + 1);
	while (buffer[i])
	{
		if (buffer[i] != ' ')
			s[j++] = buffer[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}

char **ft_cheek_tex(char **array)
{
	int j = 0;
	int i = 0;
	int no = 0;
	int so = 0;
	int we = 0;
	int ea = 0;
	int c = 0;
	int f = 0;
	char *buffer;
	int count;
	int fd = -1;
	char *s = NULL;

	buffer = NULL;
	count = 0;
	while (array[j])
	{
		i = 0;
		while (array[j] && (array[j][i] == ' '))
			i++;
		if ((array[j] + i)[0] == 'N' && (array[j] + i)[1] == 'O' && ((array[j] + i)[2] == ' ' || (array[j] + i)[2] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				no++;
				free (s);
			}
		}
		if ((array[j] + i)[0] == 'S' && (array[j] + i)[1] == 'O' && ((array[j] + i)[2] == ' ' || (array[j] + i)[2] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				so++;
				free (s);
			}
		}
		if ((array[j] + i)[0] == 'W' && (array[j] + i)[1] == 'E' && ((array[j] + i)[2] == ' ' || (array[j] + i)[2] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				we++;
				free (s);
			}
		}
		if ((array[j] + i)[0] == 'E' && (array[j] + i)[1] == 'A' && ((array[j] + i)[2] == ' ' || (array[j] + i)[2] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				ea++;
				free (s);
			}
		}
		if ((array[j] + i)[0] == 'C' && ((array[j] + i)[1] == ' ' || (array[j] + i)[1] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				c++;
				free (s);
			}
		}
		if ((array[j] + i)[0] == 'F'  && ((array[j] + i)[1] == ' ' || (array[j] + i)[1] == '\0'))
		{
			buffer = ft_skip_spaces((array[j] + i + 2));
			if (buffer[0] != '\0')
			{
				s = ft_re_alloc(buffer);
				f++;
				free (s);
			}
		}
		j++;
	}
	if (no != 1 || so != 1 || we != 1 || ea != 1)
		printf ("something messing in you file\n");
	if (f != 1 || c != 1)
		printf ("something messing in you file celling or the floor\n");
	return (NULL);
}

t_buff *ft_parsing(int ac, char **av)
{
	(void)ac;
	int fd;
	int count;
	char *s_;
	t_map *buffer;
	t_map *tmp;
	t_map *tmp1;
	t_map *tmp2;
	t_map *tmp3;
	t_map *tmp4;
	t_map *tmp5;

	(1) && (fd = -1, count = 0, s_ = "\0");

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (ft_error(NULL, "Error\n", "The correct usage is ./cub3D <filename>.cub\n"), NULL);
	
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 4) != 0 || fd == -1)
		return (perror("Error\ncub3D"), NULL);
	
	buffer = (t_map *)malloc(sizeof(t_map));
	if (!buffer)
		return (NULL);
	
	tmp = buffer;
	s_ = get_next_line(fd);
	if (!s_)
		return (free(buffer), NULL);
	
	buffer->s = ft_strdup_p(s_);
	if (!buffer->s)
		return (NULL);
	
	free(s_);
	while ((s_ = get_next_line(fd)))
	{
		tmp1 = malloc(sizeof(t_map));
		if (!tmp1)
			return(NULL);
		tmp1->s = ft_strdup_p(s_);
		free(s_);
		tmp1->next = NULL;
		tmp->next = tmp1;
		tmp = tmp->next;
	}
	tmp3 = buffer;
	while (tmp3)
		(tmp3 = tmp3->next, count++);
	t_buff *mem = (t_buff *)malloc(sizeof(t_buff));
	if (!mem)
		return (NULL);
	mem->array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!mem->array)
		return (NULL);
	int i = 0;
	while (buffer)
	{
		tmp2 = buffer;
		mem->array[i] = ft_strdup(buffer->s);
		buffer = buffer->next;
		free(tmp2->s);
		free(tmp2);
		i++;
	}
	mem->array[i] = NULL;
	mem->count = count;
	ft_util1(mem->array);
	ft_cheek_tex(mem->array);
	return (mem);
}