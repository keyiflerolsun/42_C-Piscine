/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:08:31 by osancak           #+#    #+#             */
/*   Updated: 2025/04/30 23:40:58 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_in_charset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	*ft_how_many_arr(char *str, char *charset)
{
	int	*result;
	int	i;

	result = malloc(sizeof(int) * 2);
	result[0] = 1;
	result[1] = 0;
	i = 0;
	while (str[i])
	{
		if (ft_in_charset(str[i], charset))
			result[0]++;
		else
			result[1]++;
		i++;
	}
	return (result);
}

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

char	**ft_split(char *str, char *charset)
{
	char	*temp;
	char	**result;
	int		*how_many;
	int		i[3];

	temp = ft_strdup(str);
	how_many = ft_how_many_arr(str, charset);
	result = malloc((how_many[1] + 1) * sizeof(char *));
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (str[i[0]])
	{
		if (ft_in_charset(str[i[0]], charset))
		{
			temp[i[0]] = '\0';
			result[i[2]++] = ft_strdup(&temp[i[1]]);
			i[1] = i[0] + 1;
			if (how_many[0] - 1 == i[2])
				result[i[2]] = ft_strdup(&temp[i[1]]);
		}
		i[0]++;
	}
	result[how_many[1]] = NULL;
	return (result);
}
