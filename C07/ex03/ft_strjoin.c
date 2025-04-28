/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:04:17 by osancak           #+#    #+#             */
/*   Updated: 2025/04/28 14:44:07 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_str(int size, char **strs, char *sep)
{
	char	*str;
	int		len;

	size--;
	len = ft_strlen(sep) * size;
	while (size >= 0)
	{
		len += ft_strlen(strs[size]);
		size--;
	}
	str = malloc(len + 1);
	return (str);
}

int	ft_append_str(char *dest, char *src, int idx)
{
	while (*src)
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	return (idx);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		idx;

	if (size <= 0)
		return (malloc(0));
	result = ft_get_str(size, strs, sep);
	i = 0;
	idx = 0;
	while (i < size)
	{
		idx = ft_append_str(result, strs[i], idx);
		if (i + 1 != size)
			idx = ft_append_str(result, sep, idx);
		i++;
	}
	result[idx] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void) {
	char **arr = (char *[]){"Merhaba", "Dunya", "42", "İstanbul"};
	char *gg = ft_strjoin(4, arr, ", ");
	printf("%s", gg);
	return (0);
}
*/
