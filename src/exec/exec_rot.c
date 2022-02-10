#include "exec.h"
#include <unistd.h>

int	exec_ra(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			ra(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rb(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rb(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rr(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rr(p, 0);
			return (0);
		}
		if (c == 'a')
			return (exec_rra(p));
		if (c == 'b')
			return (exec_rrb(p));
		if (c == 'r')
			return (exec_rrr(p));
	}
	return (1);
}
