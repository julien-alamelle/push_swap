/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:03:54 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 10:03:55 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"
#include "pile.h"
#include <unistd.h>

t_pile_lim	*lim_sa(t_pile_lim *p, char print)
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
	sa(ret->pile, print);
	return (ret);
}

t_pile_lim	*lim_sb(t_pile_lim *p, char print)
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
	sb(ret->pile, print);
	return (ret);
}

t_pile_lim	*lim_ss(t_pile_lim *p, char print)
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
	ss(ret->pile, print);
	return (ret);
}
