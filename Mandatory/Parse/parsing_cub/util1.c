/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:23:03 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 18:18:33 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

char	*ft_strdup_p(char *s)
{
	int		i;
	char	*p;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (free(s), p);
}

char	*ft_strjoin_m(char *s1, int add)
{
	int		i;
	char	*p;
	int		some;

	i = 0;
	some = 0;
	if (add == 0 || s1 == NULL)
		return (NULL);
	some = (int)ft_strlen(s1) + add;
	p = (char *)malloc(some + 1);
	if (!p)
		return (free (s1), NULL);
	while (s1[i] && i < some)
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
	return (free (s1), p);
}

int	ft_strlen_m(char *s, char c)
{
	int	end;

	end = 0;
	while (s[end])
		end++;
	end--;
	while (s[end] == c)
		end--;
	return ((end + 1));
}

char	*ft_skip_spaces(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[j] && s[j] == ' ')
		j++;
	return (s + j);
}
