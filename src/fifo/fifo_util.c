#include <fifo.h>
#include <stdlib.h>

t_fifo	*fifo_copy(t_fifo *f)
{
	t_fifo		*ret;
	t_fifo_cell	*cur;

	if (!f)
		return (0);
	ret = fifo_init(f->del);
	if (!ret)
		return (0);
	cur = f->first;
	while (cur)
	{
		fifo_add(ret, cur->data, 0);
		cur = cur->next;
	}
	return (ret);
}

void	fifo_apply(t_fifo *f, void (*ft)(void*))
{
	t_fifo_cell	*cur;

	if (!f)
		return ;
	cur = f->first;
	while (cur)
	{
		(*ft)(cur->data);
		cur = cur->next;
	}
}
