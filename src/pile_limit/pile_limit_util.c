/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:31:23 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/10 18:31:27 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile_limit.h"

int	pile_lim_is_sort(t_pile_lim *p)
{
	if (!p)
		return (0);
	if (p->oa > 0 || p->ub || p->ob > 0)
		return (0);
	return (pile_is_sort(p->pile));
}

t_pile_lim	*pile_lim_exec(t_pile_lim *pl, t_pile *p)
{
	t_pile	*(*data)(t_pile *, char);

	if (!pl || !p)
		return (pl);
	data = (t_pile *(*)(t_pile *, char)) fifo_get(pl->path);
	while (data)
	{
		data(p, 1);
		data = (t_pile *(*)(t_pile *, char)) fifo_get(pl->path);
	}
	return (pl);
}
