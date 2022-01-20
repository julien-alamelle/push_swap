#include "pile.h"

t_pile	*rra(t_pile *p)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	p->last_op = 32;
	p->a = (p->o)[p->a];
	return (p);
}

t_pile	*rrb(t_pile *p)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	p->last_op = 64;
	p->b = (p->o)[p->b];
	return (p);
}

t_pile	*rrr(t_pile *p)
{
	p = rrb(rra(p));
	p->last_op = 128;
	return (p);
}
