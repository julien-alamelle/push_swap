/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:03:41 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 10:03:44 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"
#include "pile.h"
#include <unistd.h>

t_pile_lim	*lim_ra(t_pile_lim *p, char print)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->ua || (p->last_op & 248))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 4;
	ra(ret->pile, print);
	if (ret->oa != -1)
	{
		++(ret->oa);
		--(ret->ua);
	}
	return (ret);
}

t_pile_lim	*lim_rb(t_pile_lim *p, char print)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->ub || (p->last_op & 244))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 8;
	rb(ret->pile, print);
	if (ret->ob != -1)
	{
		++(ret->ob);
		--(ret->ub);
	}
	return (ret);
}

t_pile_lim	*lim_rr(t_pile_lim *p, char print)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (!p->ua || !p->ub || (p->last_op & 224))
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 16;
	rr(ret->pile, print);
	if (ret->oa != -1)
	{
		++(ret->oa);
		--(ret->ua);
	}
	if (ret->ob != -1)
	{
		++(ret->ob);
		--(ret->ub);
	}
	return (ret);
}
