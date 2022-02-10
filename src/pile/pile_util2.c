/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:16:50 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:09:39 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <stdlib.h>

int	pile_is_sort(t_pile *p)
{
	int	i;

	if (!p)
		return (0);
	if (p->a)
		return (0);
	i = -1;
	while (++i < p->n)
		if (p->u[i] && p->u[i] != i + 1)
			return (0);
	return (1);
}

static t_pile	*malloc_init(int n)
{
	t_pile	*ret;

	ret = malloc(sizeof(t_pile));
	if (!ret)
		return (0);
	ret->n = n;
	ret->a = -1;
	ret->b = -1;
	ret->u = malloc(n * sizeof(int));
	ret->o = malloc(n * sizeof(int));
	if (!ret->o || !ret->u)
		return (pile_del(ret));
	return (ret);
}

static void	link_edge(t_pile *ret, t_pile *p, int *lim, int min)
{
	if (lim[0] >= 0)
	{
		(ret->o)[lim[0]] = lim[1];
		(ret->u)[lim[1]] = lim[0];
		if (lim[2] & 2)
			ret->b = lim[0];
		else
			ret->a = lim[0];
	}
	else
	{
		if (lim[2] & 2)
			ret->b = p->b - min;
		else
			ret->a = p->a - min;
	}
}

t_pile	*pile_cut(t_pile *p, int min, int max, int info)
{
	t_pile	*ret;
	int		lim[3];
	int		i;

	lim[0] = -1;
	lim[1] = -1;
	lim[2] = info;
	ret = malloc_init(max - min);
	if (!ret || !p)
		return (pile_del(ret));
	i = -1;
	while (++i < ret->n)
	{
		(ret->u)[i] = (p->u)[i + min] - min;
		(ret->o)[i] = (p->o)[i + min] - min;
		if ((ret->o)[i] >= ret->n || (ret->o)[i] < 0)
			lim[0] = i;
		if ((ret->u)[i] >= ret->n || (ret->u)[i] < 0)
			lim[1] = i;
	}
	link_edge(ret, p, lim, min);
	return (ret);
}
