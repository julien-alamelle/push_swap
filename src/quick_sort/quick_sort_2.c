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
	int	cut1;
	int	cut2;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 1));
	cut1 = min + i / 3;
	cut2 = cut1 + i / 3;
	while (i--)
	{
		rra(pile, 1);
		if (pile->a < cut1)
		{
			pb(pile, 1);
			rb(pile, 1);
		}
		else if (pile->a < cut2)
			pb(pile, 1);
	}
	qs_ua(pile, cut2, max);
	qs_ub(pile, cut1, cut2);
	qs_ob(pile, min, cut1);
	return (0);
}

int	qs_ob(t_pile *pile, int min, int max)
{
	int	cut1;
	int	cut2;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 3));
	cut1 = min + i / 3;
	cut2 = cut1 + i / 3;
	while (i--)
	{
		rrb(pile, 1);
		if (pile->b >= cut2)
			pa(pile, 1);
		else if (pile->b >= cut1)
		{
			pa(pile, 1);
			ra(pile, 1);
		}
	}
	qs_ua(pile, cut2, max);
	qs_oa(pile, cut1, cut2);
	qs_ub(pile, min, cut1);
	return (0);
}

int	qs_ua(t_pile *pile, int min, int max)
{
	int	cut1;
	int	cut2;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 0));
	cut1 = min + i / 3;
	cut2 = cut1 + i / 3;
	while (i--)
	{
		if (pile->a < cut1)
		{
			pb(pile, 1);
			rb(pile, 1);
		}
		else if (pile->a < cut2)
			pb(pile, 1);
		else
			ra(pile, 1);
	}
	qs_oa(pile, cut2, max);
	qs_ub(pile, cut1, cut2);
	qs_ob(pile, min, cut1);
	return (0);
}

int	qs_ub(t_pile *pile, int min, int max)
{
	int	cut1;
	int	cut2;
	int	i;

	i = max - min;
	if (i <= CUTLIM)
		return (perfect_sort(pile, min, max, 2));
	cut1 = min + i / 3;
	cut2 = cut1 + i / 3;
	while (i--)
	{
		if (pile->b < cut1)
			rb(pile, 1);
		else if (pile->b < cut2)
		{
			pa(pile, 1);
			ra(pile, 1);
		}
		else
			pa(pile, 1);
	}
	qs_ua(pile, cut2, max);
	qs_oa(pile, cut1, cut2);
	qs_ob(pile, min, cut1);
	return (0);
}
