/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 02:15:06 by osancak           #+#    #+#             */
/*   Updated: 2025/04/18 05:35:29 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}
