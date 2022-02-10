#include "pile_limit.h"
#include <unistd.h>

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
