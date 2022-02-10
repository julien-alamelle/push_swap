/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:03:54 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/07 18:15:29 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"

t_pile_lim	*lim_sa(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->ua < 2 || p->last_op == 2)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 2;
	fifo_add(ret->path, (void *) 1, 0);
	sa(ret->pile, 0);
	return (ret);
}

t_pile_lim	*lim_sb(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->ub < 2 || p->last_op == 2)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 2;
	fifo_add(ret->path, (void *) 2, 0);
	sb(ret->pile, 0);
	return (ret);
}

t_pile_lim	*lim_ss(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	if (p->ua < 2 || p->ub < 2 || p->last_op == 2)
		return (0);
	ret = pile_lim_copy(p);
	if (!ret)
		return (0);
	ret->last_op = 2;
	fifo_add(ret->path, (void *) 3, 0);
	ss(ret->pile, 0);
	return (ret);
}
