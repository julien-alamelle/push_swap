/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:45:17 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 16:14:29 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fifo.h"
#include <stdlib.h>

static t_fifo_cell	*fifo_cell_init(void *data)
{
	t_fifo_cell	*ret;

	ret = malloc(sizeof(t_fifo_cell));
	ret->data = data;
	ret->next = 0;
	return (ret);
}

t_fifo	*fifo_init(void (*del)(void *))
{
	t_fifo	*ret;

	ret = malloc(sizeof(t_fifo));
	ret->first = 0;
	ret->last = 0;
	ret->del = del;
	return (ret);
}

t_fifo	*fifo_del(t_fifo *f)
{
	t_fifo_cell	*cur;

	while (f->first)
	{
		cur = f->first;
		f->first = cur->next;
		if (f->del)
			(f->del)(cur->data);
		free(cur);
	}
	free(f);
	return (0);
}

void	*fifo_get(t_fifo *f)
{
	void		*ret;
	t_fifo_cell	*first;

	first = f->first;
	if (!first)
		return (0);
	f->first = first->next;
	if (!f->first)
		f->last = 0;
	ret = first->data;
	free(first);
	return (ret);
}

void	fifo_add(t_fifo *f, void *data)
{
	t_fifo_cell	*new;

	new = fifo_cell_init(data);
	if (!new)
	{
		if (f->del)
			(f->del)(data);
		return ;
	}
	if (!f->first)
		f->first = new;
	f->last->next = new;
	f->last = new;
}
