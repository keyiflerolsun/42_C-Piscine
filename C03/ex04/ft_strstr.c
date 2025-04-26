/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:45:56 by osancak           #+#    #+#             */
/*   Updated: 2025/04/20 23:13:52 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_equal(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] == to_find[i])
	{
		if (to_find[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		if ((str[i] == to_find[0]) && is_equal(&str[i], to_find))
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
