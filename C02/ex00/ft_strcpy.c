/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:21:35 by osancak           #+#    #+#             */
/*   Updated: 2025/04/16 16:30:25 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	counter;

	counter = 0;
	while (src)
	{
		if (src[counter] == '\0')
		{
			dest[counter] = '\0';
			break ;
		}
		else
		{
			dest[counter] = src[counter];
			counter++;
		}
	}
	return (dest);
}
