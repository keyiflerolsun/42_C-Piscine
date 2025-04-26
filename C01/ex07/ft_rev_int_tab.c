/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:38:54 by osancak           #+#    #+#             */
/*   Updated: 2025/04/14 19:54:49 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	zero;
	int	temp;

	zero = 0;
	size = size - 1;
	while (zero < size)
	{
		temp = tab[zero];
		tab[zero] = tab[size];
		tab[size] = temp;
		zero++;
		size--;
	}
}
