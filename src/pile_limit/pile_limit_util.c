#include "pile_limit.h"
#include "pile.h"
#include <stdlib.h>

t_pile_lim	*pile_lim_copy(t_pile_lim *p)
{
	t_pile_lim	*ret;

	if (!p)
		return (0);
	ret = malloc(sizeof(t_pile_lim));
	if (ret)
	{
		ret->pile = pile_copy(p->pile);
		if (!ret->pile)
			return (pile_lim_del(ret));
		ret->last_op = p->last_op;
		ret->ua = p->ua;
		ret->ub = p->ub;
		ret->oa = p->oa;
		ret->ob = p->ob;
	}
	return (ret);
}

t_pile_lim	*pile_lim_del(t_pile_lim *p)
{
	if (p)
	{
		pile_del(p->pile);
		free(p);
	}
	return (0);
}

int	*lim_get_pos(t_pile_lim *p)
{
	int	*ret;

	if (!p)
		return (0);
	ret = get_pos(p->pile);
	if (!ret)
		return (ret);
	if (!p->ua)
		ret[p->ua] -= 1;
	if (!p->ub)
		ret[p->ua] -= 2;
	return (ret);
}
