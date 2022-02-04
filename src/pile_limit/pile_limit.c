/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:03:07 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 10:29:29 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"
#include "pile.h"
#include <stdlib.h>

t_pile_lim	*pile_lim_copy(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	ret = malloc(sizeof(t_pile_lim));
	if (ret)
	{
		ret->pile = pile_copy(p->pile);
		if (!ret->pile)
			return (pile_lim_del(ret));
		ret->last_op = p->last_op;
		ret->ua = p->ua;
		ret->ub = p->ub;
		ret->oa = p->oa;
		ret->ob = p->ob;
	}
	return (ret);
}

t_pile_lim	*pile_lim_del(t_pile_lim *p)
{
	if (p)
	{
		pile_del(p->pile);
		free(p);
	}
	return (0);
}

int	*lim_get_pos(t_pile_lim *p)
{
	int	*ret;

	if (!p)
		return (0);
	ret = get_pos(p->pile);
	if (!ret)
		return (ret);
	if (!p->ua)
		ret[p->ua] -= 1;
	if (!p->ub)
		ret[p->ua] -= 2;
	return (ret);
}

static void	pile_lim_fill(t_pile_lim *p, int min, int max, int info)
{
	p->ua = 0;
	p->ub = 0;
	p->oa = 0;
	p->ob = 0;
	p->last_op = 0;
	if (!min)
		p->oa = -1;
	if (max == p->pile->n)
		p->ob = -1;
	if (info & 2)
	{
		p->last_op = 1;
		if (info & 1)
			p->ob = max - min;
		else
			p->ub = max - min;
	}
	else
	{
		if (info & 1)
			p->oa = max - min;
		else
			p->ua = max - min;
	}
}

t_pile_lim	*pile_lim_init(t_pile *p, int min, int max, int info)
{
	t_pile_lim	*ret;

	if (!p || max <= min || min < 0 || max > p->n)
		return (0);
	ret = malloc(sizeof(t_pile_lim));
	if (!ret)
		return (0);
	ret->pile = pile_cut(p, min, max, info);
	if (!(ret->pile))
		return (pile_lim_del(ret));
	pile_lim_fill(ret, min, max, info);
	return (ret);
}
