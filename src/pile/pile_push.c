/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:59:47 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/28 19:10:44 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <unistd.h>

static t_pile	*spa(t_pile *p)
{
	(p->u)[(p->o)[p->b]] = (p->u)[p->b];
	(p->o)[(p->u)[p->b]] = (p->o)[p->b];
	p->a = p->b;
	if (p->b == (p->u)[p->b])
		p->b = -1;
	else
		p->b = (p->u)[p->b];
	(p->o)[p->a] = p->a;
	(p->u)[p->a] = p->a;
	return (p);
}

static t_pile	*spb(t_pile *p)
{
	(p->u)[(p->o)[p->a]] = (p->u)[p->a];
	(p->o)[(p->u)[p->a]] = (p->o)[p->a];
	p->b = p->a;
	if (p->a == (p->u)[p->a])
		p->a = -1;
	else
		p->a = (p->u)[p->a];
	(p->o)[p->b] = p->b;
	(p->u)[p->b] = p->b;
	return (p);
}

t_pile	*pa(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	if (print)
		write(1, "pa\n", 3);
	if (p->a == -1)
		return (spa(p));
	(p->u)[(p->o)[p->b]] = (p->u)[p->b];
	(p->o)[(p->u)[p->b]] = (p->o)[p->b];
	(p->o)[p->b] = (p->o)[p->a];
	(p->u)[(p->o)[p->b]] = p->b;
	(p->o)[p->a] = p->b;
	if (p->b == (p->u)[p->b])
		p->b = -1;
	else
		p->b = (p->u)[p->b];
	(p->u)[(p->o)[p->a]] = p->a;
	p->a = (p->o)[p->a];
	return (p);
}

t_pile	*pb(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	if (print)
		write(1, "pb\n", 3);
	if (p->b == -1)
		return (spb(p));
	(p->u)[(p->o)[p->a]] = (p->u)[p->a];
	(p->o)[(p->u)[p->a]] = (p->o)[p->a];
	(p->o)[p->a] = (p->o)[p->b];
	(p->u)[(p->o)[p->a]] = p->a;
	(p->o)[p->b] = p->a;
	if (p->a == (p->u)[p->a])
		p->a = -1;
	else
		p->a = (p->u)[p->a];
	(p->u)[(p->o)[p->b]] = p->b;
	p->b = (p->o)[p->b];
	return (p);
}
