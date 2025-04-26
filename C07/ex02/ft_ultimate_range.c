/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:50:25 by osancak           #+#    #+#             */
/*   Updated: 2025/04/26 19:44:59 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min > max || min == max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	*range = malloc(len * 4);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (len);
}
