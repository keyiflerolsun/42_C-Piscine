/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:16:10 by osancak           #+#    #+#             */
/*   Updated: 2025/04/14 03:49:36 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bidi(int baslangic, int idx, int basamak, char *rakamlar)
{
	while (baslangic <= 9)
	{
		rakamlar[idx] = baslangic + '0';
		if (basamak == 1)
		{
			write(1, rakamlar, idx + 1);
			if (rakamlar[0] != (10 - (idx + basamak) + '0'))
			{
				write(1, ", ", 2);
			}
		}
		else
		{
			bidi(baslangic + 1, idx + 1, basamak - 1, rakamlar);
		}
		baslangic++;
	}
}

void	ft_print_combn(int n)
{
	char	rakamlar[10];

	bidi(0, 0, n, rakamlar);
}
