/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:53:21 by osancak           #+#    #+#             */
/*   Updated: 2025/04/13 00:18:29 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	gg(char ilk, char son)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = ilk / 10 + '0';
	b = ilk % 10 + '0';
	c = son / 10 + '0';
	d = son % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &" ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (ilk != 98 || son != 99)
	{
		write(1, &", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	mahmut;
	char	ismet;

	mahmut = 0;
	while (mahmut <= 98)
	{
		ismet = mahmut + 1;
		while (ismet <= 99)
		{
			gg(mahmut, ismet);
			ismet++;
		}
		mahmut++;
	}
}
