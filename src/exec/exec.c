#include "exec.h"
#include <unistd.h>

static int	exec_p(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == 'a')
			return (exec_pa(p));
		if (c == 'b')
			return (exec_pb(p));
	}
	return (1);
}

static int	exec_s(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == 'a')
			return (exec_sa(p));
		if (c == 'b')
			return (exec_sb(p));
		if (c == 's')
			return (exec_ss(p));
	}
	return (1);
}

static int	exec_r(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == 'a')
			return (exec_ra(p));
		if (c == 'b')
			return (exec_rb(p));
		if (c == 'r')
			return (exec_rr(p));
	}
	return (1);
}

void	exec_stdin(t_pile *p)
{
	char	c;
	int		err;

	err = 0;
	while (read(0, &c, 1) && !err)
	{
		if (c == 'p')
			err = exec_p(p);
		else if (c == 's')
			err = exec_s(p);
		else if (c == 'r')
			err = exec_r(p);
		else
			err = 1;
	}
	if (err)
		write(2, "Error\n", 6);
	else if (pile_is_sort(p))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
