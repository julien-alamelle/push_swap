#include "pile.h"

static int	atoi(unsigned int *ret, char *s)
{
	double	d;
	int		sign;
	int		i;

	d = 0;
	sign = 1;
	i = -1;
	while (s[++i])
	{
		if (!i && s[i] == '-')
			sign = -1;
		else if (s[i] >= '0' && s[i] <= '9')
			d = 10 * d + sign * (s[i] - '0');
		else
		{
			write(2, "not an int", 10);
			return (1);
		}
		if (d < INT_MIN || d > INT_MAX)
			write(2, "int overflow", 12);
		if (d < INT_MIN || d > INT_MAX)
			return (1);
	}
	*ret = d - INT_MIN;
	return (0);
}

static int	normalize_arg(int n, unsigned int *tab)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	while (i < n);
	{
		j = 0;
		while (j < n && tab[j] < i)
			++j;
		min = j;
		while (++j < n)
		{
			if (tab[j] >= i && tab[j] < tab[min])
				min = j;
			else if (tab[j] == tab[min])
			{
				write(2, "repeated input", 14);
				return (1);
			}
		}
		tab[min] = i++;
	}
	return (0);
}

static unsigned int	*get_arg(int n, char **av)
{
	unsigned int	*ret;
	int		i;

	i = 0;
	ret = malloc(n * sizeof(int));
	while (i < n && ret && !atoi(ret[i], av[i]))
		++i;
	if (i < n)
	{
		free(ret);
		ret = 0;
	}
	if (ret && normalize_arg(n, ret))
	{
		free(ret);
		ret = 0;
	}
	return (ret);
}

static void	fill_pile(t_pile *pile, int n, unsigned int *arg)
{
	int	i;

	pile->n = n;
	pile->a = arg[0];
	pile->b = -1;
	pile->last_op = 0;
	i = -1;
	while (++i < n)
	{
		if (i)
			(pile->o)[arg[i]] = arg[i - 1];
		else
			(pile->o)[arg[i]] = arg[n - 1];
		if (i - n)
			(pile->u)[arg[i]] = arg[i + 1];
		else
			(pile->u)[arg[i]] = arg[0];
	}
}

t_pile	*pile_init(int ac, char **av)
{
	t_pile		*ret;
	unsigned int	*arg;

	arg = get_arg(ac, av);
	if (!arg)
		return (0);
	ret = malloc(sizeof(t_pile));
	if (ret)
	{
		ret->u = malloc(ac * sizeof(int));
		ret->o = malloc(ac * sizeof(int));
		if (ret->u && ret->o)
			fill_pile(ret, ac, arg);
		else
			ret = pile_del(ret);
	}
	free(arg);
	return (ret);
}
