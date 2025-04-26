/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:20:45 by osancak           #+#    #+#             */
/*   Updated: 2025/04/13 11:04:33 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	satir_yaz(int sutun, char basla, char bitir, char aralik)
{
	ft_putchar(basla);
	while (sutun - 2 > 0)
	{
		ft_putchar(aralik);
		sutun--;
	}
	if (sutun > 1)
		ft_putchar(bitir);
}

void	rush(int x, int y)
{
	char	satir;
	char	sutun;

	satir = y;
	sutun = x;
	if (satir <= 0 || sutun <= 0)
	{
		write(1, ":)\n", 3);
		return ;
	}
	satir_yaz(sutun, 'A', 'C', 'B');
	if (satir != 1)
		ft_putchar('\n');
	if (satir > 0)
	{
		while (satir - 2 > 0)
		{
			satir_yaz(sutun, 'B', 'B', ' ');
			ft_putchar('\n');
			satir--;
		}
	}
	if (satir != 1)
		satir_yaz(sutun, 'A', 'C', 'B');
	ft_putchar('\n');
}
