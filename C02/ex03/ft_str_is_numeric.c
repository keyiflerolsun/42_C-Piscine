/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:53:46 by osancak           #+#    #+#             */
/*   Updated: 2025/04/16 21:05:00 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	check;

	check = 1;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			check = 0;
		str++;
	}
	return (check);
}
