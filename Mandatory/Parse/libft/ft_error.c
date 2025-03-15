/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:24:19 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/14 22:25:47 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"

void	ft_error1(char *str1)
{
	if (str1 != NULL)
		write(2, str1, ft_strlen(str1));
}

void	ft_error2(char *str1, char *str2)
{
	if (str1 != NULL)
		write(2, str1, ft_strlen(str1));
	if (str2 != NULL)
		write(2, str2, ft_strlen(str2));
}

void	ft_error3(char *str1, char *str2, char *str3)
{
	if (str1 != NULL)
		write(2, str1, ft_strlen(str1));
	if (str2 != NULL)
		write(2, str2, ft_strlen(str2));
	if (str3 != NULL)
		write(2, str3, ft_strlen(str3));
}
