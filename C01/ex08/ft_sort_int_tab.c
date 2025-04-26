/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:41:30 by osancak           #+#    #+#             */
/*   Updated: 2025/04/14 20:04:06 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	zero;
	int	swap;

	zero = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		while (zero < size -1)
		{
			if (tab[zero] > tab[zero + 1])
			{
				temp = tab[zero];
				tab[zero] = tab[zero + 1];
				tab[zero + 1] = temp;
				swap = 1;
			}
			zero++;
		}
		zero = 0;
	}
}
