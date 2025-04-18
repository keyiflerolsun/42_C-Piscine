/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:03:32 by osancak           #+#    #+#             */
/*   Updated: 2025/04/17 19:03:55 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;

	counter = 0;
	if (!(size > 0))
	{
		return (counter);
	}
	while (src[counter])
	{
		if (counter + 1 == size)
			dest[counter] = '\0';
		else
			dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (counter);
}
