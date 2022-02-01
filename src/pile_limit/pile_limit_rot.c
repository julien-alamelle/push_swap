/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:00:22 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/20 19:28:37 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <unistd.h>

t_pile	*ra(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	p->last_op = 4;
	if (print)
		write(1, "ra\n", 3);
	p->a = (p->u)[p->a];
	return (p);
}

t_pile	*rb(t_pile *p, char print)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	p->last_op = 8;
	if (print)
		write(1, "rb\n", 3);
	p->b = (p->u)[p->b];
	return (p);
}

t_pile	*rr(t_pile *p, char print)
{
	p = rb(ra(p, 0), 0);
	p->last_op = 16;
	if (print)
		write(1, "rr\n", 3);
	return (p);
}
