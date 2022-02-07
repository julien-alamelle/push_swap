/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_rrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:03:50 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/07 18:15:47 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"

# include <stdio.h>
t_pile_lim	*lim_rra(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->oa || (p->oa == -1 && !p->ua) || (p->last_op & 84))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 32;
	fifo_add(ret->path, (void *) 9, 0);
	rra(ret->pile, 0);
	if (ret->oa != -1)
	{
		++(ret->ua);
		--(ret->oa);
	}
dprintf(2,"rra ");
	return (ret);
}

t_pile_lim	*lim_rrb(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->ob || (p->ob == -1 && !p->ub) || (p->last_op & 56))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 64;
	fifo_add(ret->path, (void *) 10, 0);
	rrb(ret->pile, 0);
	if (ret->ob != -1)
	{
		++(ret->ub);
		--(ret->ob);
	}
dprintf(2,"rrb ");
	return (ret);
}

t_pile_lim	*lim_rrr(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->oa || !p->ob || (p->oa == -1 && !p->ua) || (p->ob == -1 && !p->ub)
		|| (p->last_op & 124))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 128;
	fifo_add(ret->path, (void *) 11, 0);
	rrr(ret->pile, 0);
	if (ret->oa != -1)
	{
		++(ret->ua);
		--(ret->oa);
	}
	if (ret->ob != -1)
	{
		++(ret->ub);
		--(ret->ob);
	}
dprintf(2,"rrr ");
	return (ret);
}
