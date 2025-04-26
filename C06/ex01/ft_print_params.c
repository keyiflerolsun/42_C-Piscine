/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:27:55 by osancak           #+#    #+#             */
/*   Updated: 2025/04/23 12:33:34 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	param;
	int	p_arr;

	if (argc < 1)
		return (1);
	param = 1;
	p_arr = 0;
	while (argv[param])
	{
		p_arr = 0;
		while (argv[param][p_arr])
		{
			write(1, &argv[param][p_arr], 1);
			p_arr++;
		}
		param++;
		write(1, "\n", 1);
	}
	return (0);
}
