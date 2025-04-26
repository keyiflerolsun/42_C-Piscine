/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:14:06 by osancak           #+#    #+#             */
/*   Updated: 2025/04/26 19:44:07 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(i + 1);
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}
