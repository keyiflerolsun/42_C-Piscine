/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:59:33 by osancak           #+#    #+#             */
/*   Updated: 2025/04/21 22:30:02 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	toi;
	int	sign;

	sign = 1;
	toi = 0;
	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '+' || str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == '-')
		{
			i++;
			sign = sign * -1;
		}
		else
			return (0);
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		toi = toi * 10 + (str[i] - '0');
		i++;
	}
	return (toi * sign);
}
