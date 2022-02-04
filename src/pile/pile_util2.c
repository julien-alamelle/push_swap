/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:16:50 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:09:39 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include <stdlib.h>

int	pile_is_sort(t_pile *p)
{
	int	i;

	i = -1;
	while (++i < p->n)
		if (p->u[i] && p->u[i] != i + 1)
			return (0);
	return (1);
}

static t_pile	*malloc_init(int n)
{
	t_pile	*ret;

	ret = malloc(sizeof(t_pile));
	if (!ret)
		return (0);
	ret->n = n;
	ret->a = -1;
	ret->b = -1;
	ret->u = malloc(n * sizeof(int));
	ret->o = malloc(n * sizeof(int));
	if (!ret->o || !ret->u)
		return (pile_del(ret));
	return (ret);
}

static void	link_start(t_pile *ret, t_pile *p, int start, int end, int info)
{
	if (start >= 0)
	{
		(ret->o)[start] = end;
		(ret->u)[end] = start;
		if (info & 2)
			ret->b = start;
		else
			ret->a = start;
	}
	else
	{
		if (info & 2)
			ret->b = p->b;
		else
			ret->a = p->a;
	}
}

t_pile	*pile_cut(t_pile *p, int min, int max, int info)
{
	t_pile	*ret;
	int		start;
	int		end;
	int		i;

	start = -1;
	end = -1;
	ret = malloc_init(max - min);
	if (!ret || !p)
		return (pile_del(ret));
	i = -1;
	while (++i < ret->n)
	{
		(ret->u)[i] = (p->u)[i + min] - min;
		(ret->o)[i] = (p->o)[i + min] - min;
		if ((ret->o)[i] >= ret->n || (ret->o)[i] < 0)
			start = i;
		if ((ret->u)[i] >= ret->n || (ret->u)[i] < 0)
			end = i;
	}
	link_start(ret, p, start, end, info);
	return (ret);
}
