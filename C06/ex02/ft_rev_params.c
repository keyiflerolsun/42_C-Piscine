/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:34:39 by osancak           #+#    #+#             */
/*   Updated: 2025/04/23 12:42:59 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	p_arr;

	while (argc > 1 && argv[argc - 1])
	{
		p_arr = 0;
		while (argv[argc - 1][p_arr])
		{
			write(1, &argv[argc - 1][p_arr], 1);
			p_arr++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (1);
}
