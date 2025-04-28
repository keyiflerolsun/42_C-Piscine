/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osancak <osancak@student.42istanbul.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:47:33 by osancak           #+#    #+#             */
/*   Updated: 2025/04/27 11:57:38 by osancak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ((Value) * ((Value) > 0)) - ((Value) * ((Value) < 0))
//# define ABS(Value) ((Value) < 0) ? -(Value) : (Value)

#endif
