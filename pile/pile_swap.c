#include "pile.h"

t_pile	*sa(t_pile *p)
{
	if (!p)
		return (p);
	if (p->a == -1)
		return (p);
	p->last_op = 2;
	if ((p->u)[p->a] == (p->o)[p->a])
		return (ra(p));
	(p->o)[(p->u)[p->a]] = (p->o)[p->a];
	(p->u)[(p->o)[p->a]] = (p->u)[p->a];
	(p->o)[p->a] = (p->u)[p->a];
	(p->u)[p->a] = (p->u)[(p->u)[p->a]];
	(p->o)[(p->u)[p->a]] = p->a;
	(p->o)[(p->u)[p->a]] = p->a;
	p->a = (p->o)[p->a];
	return (p);
}

t_pile	*sb(t_pile *p)
{
	if (!p)
		return (p);
	if (p->b == -1)
		return (p);
	p->last_op = 2;
	if ((p->u)[p->b] == (p->o)[p->b])
		return (rb(p));
	(p->o)[(p->u)[p->b]] = (p->o)[p->b];
	(p->u)[(p->o)[p->b]] = (p->u)[p->b];
	(p->o)[p->b] = (p->u)[p->b];
	(p->u)[p->b] = (p->u)[(p->u)[p->b]];
	(p->o)[(p->u)[p->b]] = p->b;
	(p->o)[(p->u)[p->b]] = p->b;
	p->b = (p->o)[p->b];
	return (p);
}

t_pile	*ss(t_pile *p)
{
	p = sb(sa(p));
	p->last_op = 2;
	return (p);
}
