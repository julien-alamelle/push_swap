/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:06:41 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/07 18:16:15 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"

# include <stdio.h>
t_pile_lim	*lim_pa(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->last_op == 0 || p->ub == 0)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	pa(ret->pile, 0);
	ret->last_op = 1;
	fifo_add(ret->path, (void *) 4, 0);
	ret->ub--;
	ret->ua++;
dprintf(2,"pa ");
//pile_lim_print(ret);
	return (ret);
}

t_pile_lim	*lim_pb(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->last_op == 1 || p->ua == 0)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	pb(ret->pile, 0);
	ret->last_op = 0;
	fifo_add(ret->path, (void *) 5, 0);
	ret->ua--;
	ret->ub++;
dprintf(2,"pb ");
	return (ret);
}
