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
	int	cut1;
	int	cut2;
	int	i;

	i = pile->n;
	if (i <= CUTLIM)
		return (perfect_sort(pile, 0, pile->n, 0));
	cut1 = i / 3;
	cut2 = cut1 + i / 3;
	while (i--)
	{
		if (pile->a < cut1)
		{
			pb(pile, 1);
			rb(pile, 2);
		}
		else if (pile->a >= cut2)
			ra(pile, 1);
		else
			pb(pile, 1);
	}
	qs_a(pile, cut2, pile->n);
	qs_ub(pile, cut1, cut2);
	qs_b(pile, 0, cut1);
	return (0);
}

int	qs_a(t_pile *pile, int min, int max)
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
			rb(pile, 2);
		}
		else if (pile->a >= cut2)
			ra(pile, 1);
		else
			pb(pile, 1);
	}
	qs_a(pile, cut2, max);
	qs_ub(pile, cut1, cut2);
	qs_ob(pile, min, cut1);
	return (0);
}

int	qs_b(t_pile *pile, int min, int max)
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
			rb(pile, 2);
		else if (pile->b >= cut2)
			pa(pile, 1);
		else
		{
			pa(pile, 1);
			ra(pile, 1);
		}
	}
	qs_ua(pile, cut2, max);
	qs_oa(pile, cut1, cut2);
	qs_b(pile, min, cut1);
	return (0);
}
