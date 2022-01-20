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

t_fifo	*fifo_init(void *del(void *))
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
		f->del(cur->data);
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
	t_fifo_cell	new;

	new = 0;
	while (!new)
		new = fifo_cell_init(data);
	f->last->next = new;
	f->last = new;
}
