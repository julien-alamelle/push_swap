/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:05:22 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/25 14:47:38 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# ifndef CUTLIM
#  define CUTLIM 6
# endif

# include "pile.h"

int	quick_sort(t_pile *pile);
int	qs_a(t_pile *pile, int min, int max);
int	qs_b(t_pile *pile, int min, int max);
int	qs_ua(t_pile *pile, int min, int max);
int	qs_ub(t_pile *pile, int min, int max);
int	qs_oa(t_pile *pile, int min, int max);
int	qs_ob(t_pile *pile, int min, int max);

#endif
