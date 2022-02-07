#include "pile_limit.h"
#include <unistd.h>

# include <stdio.h>
static void	ft_hack(void *data)
{
	const char	*print[11][2] = {{"sa", (char *) 3},{"sb", (char *) 3},{"ss", (char *) 3},{"pa", (char *) 3},{"pb", (char *) 3},{"ra", (char *) 3},{"rb", (char *) 3},{"rr", (char *) 3},{"rra", (char *) 4},{"rrb", (char *) 4},{"rrr", (char *) 4}};
	long		cur;

	cur = (long) data;
dprintf(2, "%s ", print[cur - 1][0]);
dprintf(2, "\n");
}

int	pile_lim_is_sort(t_pile_lim *p)
{
	if (!p)
		return (0);
	if (p->oa > 0 || p->ub || p->ob > 0)
		return (0);
	return (pile_is_sort(p->pile));
}

t_pile_lim	*pile_lim_print(t_pile_lim *p)
{
	if (!p)
		return (0);
	if (p->ua >= 4)
	{
printf("%d %d %d %d start\n", p->ua, p->oa, p->ub, p->ob);
		fifo_apply(p->path, ft_hack);
printf("%d %d %d %d end\n", p->ua, p->oa, p->ub, p->ob);
	}
	return (p);
}

t_pile_lim	*pile_lim_exec(t_pile_lim *pl, t_pile *p)
{
	t_pile	*(*print[11])(t_pile *, char) = {sa, sb, ss, pa, pb,
						ra, rb, rr, rra, rrb, rrr};
	void			*data;

	if (!pl || !p)
		return (0);
	data = fifo_get(pl->path);
	while (data)
	{
		(*(print[(long) data - 1]))(p, 1);
		data = fifo_get(pl->path);
	}
	return (pl);
}
