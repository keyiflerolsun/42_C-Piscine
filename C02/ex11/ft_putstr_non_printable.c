/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:32:00 by osancak           #+#    #+#             */
/*   Updated: 2025/04/17 23:10:32 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	char2hex(char c)
{
	char	left;
	char	right;
	char	*hex_arr;

	hex_arr = "abcdef";
	left = c / 16;
	right = c % 16;
	right = hex_arr[right % 10];
	left = left + '0';
	print('\\');
	print(left);
	print(right);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str >= ' ' && *str <= '~')
			print(*str);
		else
			char2hex(*str);
		str++;
	}
}
