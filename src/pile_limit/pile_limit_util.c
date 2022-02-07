#include "pile_limit.h"
#include <unistd.h>

static void	ft_hack(void *data)
{
	const char	*print[11][2] = {{"sa\n", (char *) 3},{"sb\n", (char *) 3},{"ss\n", (char *) 3},{"pa\n", (char *) 3},{"pb\n", (char *) 3},{"ra\n", (char *) 3},{"rb\n", (char *) 3},{"rr\n", (char *) 3},{"rra\n", (char *) 4},{"rrb\n", (char *) 4},{"rrr\n", (char *) 4}};
	const char	**cur;

	cur = print[(long) data];
	write(1, cur[0], (long) cur[1]);
}

int	pile_lim_is_sort(t_pile_lim *p)
{
	if (!p)
		return (0);
	if (p->oa > 0 || p->ub || p->ob > 0)
		return (0);
	return (pile_is_sort(p->pile));
}

# include <stdio.h>
t_pile_lim	*pile_lim_print(t_pile_lim *p)
{
printf("%d %d %d %d\n", p->ua, p->oa, p->ub, p->ob);
	if (p)
		fifo_apply(p->path, ft_hack);
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
