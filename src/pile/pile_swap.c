/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:00:33 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/28 19:12:04 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <unistd.h>

t_pile	*sa(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	if (print)
		write(1, "sa\n", 3);
	if ((p->u)[p->a] == (p->o)[p->a])
		return (ra(p, 0));
	(p->o)[(p->u)[p->a]] = (p->o)[p->a];
	(p->u)[(p->o)[p->a]] = (p->u)[p->a];
	(p->o)[p->a] = (p->u)[p->a];
	(p->u)[p->a] = (p->u)[(p->u)[p->a]];
	(p->o)[(p->u)[p->a]] = p->a;
	(p->o)[(p->u)[p->a]] = p->a;
	p->a = (p->o)[p->a];
	return (p);
}

t_pile	*sb(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	if (print)
		write(1, "sb\n", 3);
	if ((p->u)[p->b] == (p->o)[p->b])
		return (rb(p, 0));
	(p->o)[(p->u)[p->b]] = (p->o)[p->b];
	(p->u)[(p->o)[p->b]] = (p->u)[p->b];
	(p->o)[p->b] = (p->u)[p->b];
	(p->u)[p->b] = (p->u)[(p->u)[p->b]];
	(p->o)[(p->u)[p->b]] = p->b;
	(p->o)[(p->u)[p->b]] = p->b;
	p->b = (p->o)[p->b];
	return (p);
}

t_pile	*ss(t_pile *p, char print)
{
	p = sb(sa(p, 0), 0);
	if (print)
		write(1, "ss\n", 3);
	return (p);
}
