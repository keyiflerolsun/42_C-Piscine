/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:48:17 by osancak           #+#    #+#             */
/*   Updated: 2025/04/27 12:30:04 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_args(char **argv)
{
	char	*temp;
	int		swap;
	int		i;

	swap = 1;
	i = 1;
	while (swap)
	{
		swap = 0;
		while (argv[i] && argv[i + 1])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				swap = 1;
			}
			i++;
		}
		i = 1;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	i_param;

	(void) argc;
	ft_sort_args(argv);
	i = 1;
	i_param = 0;
	while (argv[i])
	{
		i_param = 0;
		while (argv[i][i_param])
		{
			write(1, &argv[i][i_param], 1);
			i_param++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
