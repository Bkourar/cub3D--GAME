/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbege.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:03:28 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/11/01 11:12:21 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garb	**get_last_node(void)
{
	static t_garb	*node;

	node = NULL;
	return (&node);
}

void	gc_free_all(void)
{
	t_garb	**head;
	t_garb	*node;
	t_garb	*next_n;

	head = get_last_node();
	node = *head;
	while (node != NULL)
	{
		next_n = node->next;
		free(node->ptr);
		free(node);
		node = next_n;
	}
	head = NULL;
}

void	*gc_malloc(size_t size)
{
	t_garb	**head;
	t_garb	*node;
	char	*ptr;

	head = get_last_node();
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = (t_garb *)malloc(sizeof(t_garb));
	if (!node)
		return (free (ptr), NULL);
	node->ptr = ptr;
	node->next = *head;
	*head = node;
	return (ptr);
}
