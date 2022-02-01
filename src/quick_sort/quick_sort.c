/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:01:35 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/25 17:34:33 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"
#include <unistd.h>

int	quick_sort(t_pile *pile)
{
	int	cut;
	int	i;

	i = pile->n;
	if (i <= 1)
		return (0); //TODO
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
	if (i <= 1)
		return (0); //TODO
	cut = min + i / 2;
	while (i--)
	{
		if (pile->a < cut)
			pb(pile, 1);
		else
			ra(pile, 1);
	}
	return (qs_a(pile, cut, max) + qs_ob(pile, min, cut) + max - min);
}

int	qs_b(t_pile *pile, int min, int max)
{
	int	cut;
	int	i;

	i = max - min;
	if (i <= 1)
	{
		pa(pile, 1);
		return (1); //TODO
	}
	cut = min + i / 2;
	while (i--)
	{
		if (pile->b < cut)
			rb(pile, 1);
		else
			pa(pile, 1);
	}
	return (qs_oa(pile, cut, max) + qs_b(pile, min, cut) + max - min);
}
