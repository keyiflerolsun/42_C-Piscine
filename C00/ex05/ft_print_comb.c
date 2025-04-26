/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:57:03 by osancak           #+#    #+#             */
/*   Updated: 2025/04/13 00:18:17 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	kurek(char mahmut, char hasan, char ismet)
{
	write(1, &mahmut, 1);
	write(1, &hasan, 1);
	write(1, &ismet, 1);
}

void	ft_print_comb(void)
{
	char	mahmut;
	char	hasan;
	char	ismet;

	mahmut = '0';
	while (mahmut <= '7')
	{
		hasan = mahmut + 1;
		while (hasan <= '8')
		{
			ismet = hasan + 1;
			while (ismet <= '9')
			{
				kurek(mahmut, hasan, ismet);
				if (mahmut != '7' || hasan != '8' || ismet != '9')
				{
					write(1, &", ", 2);
				}
				ismet++;
			}
			hasan++;
		}
		mahmut++;
	}
}
