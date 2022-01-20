#include "pile.h"

t_pile	*ra(t_pile *p)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	p->last_op = 4;
	p->a = (p->u)[p->a];
	return (p);
}

t_pile	*rb(t_pile *p)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	p->last_op = 8;
	p->b = (p->u)[p->b];
	return (p);
}

t_pile	*rr(t_pile *p)
{
	p = rb(ra(p));
	p->last_op = 16;
	return (p);
}
