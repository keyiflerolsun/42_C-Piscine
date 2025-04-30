/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:42:30 by osancak           #+#    #+#             */
/*   Updated: 2025/04/30 17:51:49 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnum(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnum(nb / 10);
		ft_putnum(nb % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).size != 0 && (*par).str != 0 && (*par).copy != 0)
	{
		ft_putstr((*par).str);
		ft_putchar('\n');
		ft_putnum((*par).size);
		ft_putchar('\n');
		ft_putstr((*par).copy);
		ft_putchar('\n');
		par++;
	}
}
