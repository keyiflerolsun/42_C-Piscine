/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:21:56 by osancak           #+#    #+#             */
/*   Updated: 2025/04/17 00:23:39 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	change;

	change = 1;
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			change = 0;
		str++;
	}
	return (change);
}
