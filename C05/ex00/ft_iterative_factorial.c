/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:53:05 by osancak           #+#    #+#             */
/*   Updated: 2025/04/22 19:25:44 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	temp;

	temp = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (nb > 1)
	{
		temp = temp * (nb - 1);
		nb--;
	}
	return (temp);
}
