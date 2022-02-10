#include "exec.h"
#include <unistd.h>

int	exec_rra(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rra(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rrb(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rrb(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rrr(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rrr(p, 0);
			return (0);
		}
	}
	return (1);
}
