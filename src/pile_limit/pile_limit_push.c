/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:06:41 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/01 17:07:31 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include "pile_limit.h"

t_pile_lim	*lim_pa(t_pile_lim *p, char print)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->last_op == 0 || p->ub == 0)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	pa(ret->pile, print);
	ret->last_op = 1;
	ret->ub--;
	ret->ua++;
	return (ret);
}

t_pile_lim	*lim_pb(t_pile_lim *p, char print)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->last_op == 1 || p->ua == 0)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	pb(ret->pile, print);
	ret->last_op = 0;
	ret->ua--;
	ret->ub++;
	return (ret);
}
