/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:19:16 by osancak           #+#    #+#             */
/*   Updated: 2025/04/22 12:41:23 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_equal(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (str1[i] == '\0' && str2[i] == '\0');
}

int	is_base(char *str)
{
	if (is_equal(str, "0123456789abcdef"))
		return (16);
	if (is_equal(str, "0123456789"))
		return (10);
	if (is_equal(str, "01"))
		return (2);
	if (is_equal(str, "poneyvif"))
		return (8);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;
	char	tmp;

	base_num = is_base(base);
	if (!base_num)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr > base_num)
	{
		ft_putnbr_base(nbr / base_num, base);
		ft_putnbr_base(nbr % base_num, base);
	}
	else
	{
		tmp = base[nbr];
		write(1, &tmp, 1);
	}
}
