/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:01:35 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:14:27 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"
#include "perfect_sort.h"

int	quick_sort(t_pile *pile)
{
	int	cut;
	int	i;

	i = pile->n;
	if (i <= CUTLIM)
		return (perfect_sort(pile, 0, pile->n, 0));
	cut = i / 2;
	while (i--)
	{
		if (pile->a < cut)
			pb(pile, 1);
		else
			ra(pile, 1);
	}
	return (qs_a(pile, cut, pile->n) + qs_b(pile, 0, cut) + pile->n);
}

int	qs_a(t_pile *pile, int min, int max)
{
	int	cut;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 0));
	cut = min + i / 2;
	while (i--)
	{
		if (pile->a < cut)
			pb(pile, 1);
		else
			ra(pile, 1);
	}
	return (qs_a(pile, cut, max) + qs_ub(pile, min, cut) + max - min);
}

int	qs_b(t_pile *pile, int min, int max)
{
	int	cut;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 2));
	cut = min + i / 2;
	while (i--)
	{
		if (pile->b < cut)
			rb(pile, 1);
		else
			pa(pile, 1);
	}
	return (qs_ua(pile, cut, max) + qs_b(pile, min, cut) + max - min);
}
