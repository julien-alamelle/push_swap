/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:52:08 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/25 17:33:21 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"
#include "perfect_sort.h"

int	qs_oa(t_pile *pile, int min, int max)
{
	int	cut;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 1));
	cut = min + i / 2;
	while (i--)
	{
		rra(pile, 1);
		if (pile->a < cut)
			pb(pile, 1);
	}
	return (qs_ua(pile, cut, max) + qs_ub(pile, min, cut)
		+ 3 * (max - min) / 2);
}

int	qs_ob(t_pile *pile, int min, int max)
{
	int	cut;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 3));
	cut = min + i / 2;
	while (i--)
	{
		rrb(pile, 1);
		if (pile->b >= cut)
			pa(pile, 1);
	}
	return (qs_ua(pile, cut, max) + qs_ub(pile, min, cut)
		+ 3 * (max - min + 1) / 2 - 1);
}

int	qs_ua(t_pile *pile, int min, int max)
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
	return (qs_oa(pile, cut, max) + qs_ub(pile, min, cut) + max - min);
}

int	qs_ub(t_pile *pile, int min, int max)
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
	return (qs_ua(pile, cut, max) + qs_ob(pile, min, cut) + max - min);
}
