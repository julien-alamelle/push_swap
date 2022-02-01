/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:00:26 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/28 19:11:29 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <unistd.h>

t_pile	*rra(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	if (print)
		write(1, "rra\n", 4);
	p->a = (p->o)[p->a];
	return (p);
}

t_pile	*rrb(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	if (print)
		write(1, "rrb\n", 4);
	p->b = (p->o)[p->b];
	return (p);
}

t_pile	*rrr(t_pile *p, char print)
{
	p = rrb(rra(p, 0), 0);
	if (print)
		write(1, "rrr\n", 4);
	return (p);
}
