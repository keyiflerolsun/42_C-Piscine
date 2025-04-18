/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:05:35 by osancak           #+#    #+#             */
/*   Updated: 2025/04/16 23:44:36 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	check;

	check = 1;
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			check = 0;
		str++;
	}
	return (check);
}
