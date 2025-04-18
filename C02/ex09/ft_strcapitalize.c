/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:26:47 by osancak           #+#    #+#             */
/*   Updated: 2025/04/18 23:33:51 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_low(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	else
		return (0);
}

int	is_up(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	else
		return (0);
}

int	is_space(char str)
{
	if (!is_low(str) && !is_up(str) && !(str >= '0' && str <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (is_up(str[idx]))
			str[idx] = str[idx] + 32;
		if (idx == 0 && is_low(str[idx]))
			str[idx] = str[idx] - 32;
		else if (is_space(str[idx - 1]) && is_low(str[idx]))
			str[idx] = str[idx] - 32;
		idx++;
	}
	return (str);
}
