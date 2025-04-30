/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:08:31 by osancak           #+#    #+#             */
/*   Updated: 2025/05/01 01:19:31 by osancak          ###   ########.fr       */
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

int	*ft_counts(char *str, char *charset)
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
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

void	ft_split_loop(char *temp, char **result, char *charset)
{
	int	s_i;
	int	w_s;
	int	w_i;

	s_i = 0;
	w_s = 0;
	w_i = 0;
	while (temp[s_i])
	{
		if (ft_in_charset(temp[s_i], charset))
		{
			temp[s_i] = '\0';
			result[w_i] = ft_strdup(&temp[w_s]);
			w_i++;
			w_s = s_i + 1;
		}
		s_i++;
	}
	result[w_i] = ft_strdup(&temp[w_s]);
	result[w_i + 1] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*temp;
	int		*counts;

	temp = ft_strdup(str);
	if (!temp)
		return (NULL);
	counts = ft_counts(str, charset);
	if (!counts)
		return (NULL);
	result = malloc((counts[0] + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_split_loop(temp, result, charset);
	free(counts);
	free(temp);
	return (result);
}
