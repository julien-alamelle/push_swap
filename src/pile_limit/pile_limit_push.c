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
	if (!p)
		return (p);
	if (p->last_op == 0 || p->ub == 0)
		return (pile_lim_del(p));
	pa(p->pile, print);
	p->last_op = 1;
	p->ub--;
	p->ua++;
	return (p);
}

t_pile_lim	*lim_pb(t_pile_lim *p, char print)
{
	if (!p)
		return (p);
	if (p->last_op == 1 || p->ua == 0)
		return (pile_lim_del(p));
	pb(p->pile, print);
	p->last_op = 0;
	p->ua--;
	p->ub++;
	return (p);
}
