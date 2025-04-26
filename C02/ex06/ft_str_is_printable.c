/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:24:13 by osancak           #+#    #+#             */
/*   Updated: 2025/04/18 02:12:09 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	change;

	change = 1;
	while (*str)
	{
		if (!(*str >= ' ' && *str <= '~'))
			change = 0;
		str++;
	}
	return (change);
}
