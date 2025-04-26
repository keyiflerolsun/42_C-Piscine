/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:31:33 by osancak           #+#    #+#             */
/*   Updated: 2025/04/27 01:39:21 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

// # define ABS(Value) ((Value) < 0 ? -(Value) : (Value))
# define ABS(Value) (((Value) * ((Value) > 0)) - ((Value) * ((Value) < 0)))

#endif
