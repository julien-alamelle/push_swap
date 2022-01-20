#include "quick_sort.h"
#include <unistd.h>

void	qs_uA(t_pile *pile, int min, int max)
{
	int cut;
	int i;

	i = max-min;
	if (i <= 1)
	{
		rra(pile);
		write(1, "rra\n", 4);
		return ; //TODO
	}
	cut = min + i / 2;
	while (i--)
	{
		rra(pile);
		write(1, "rra\n", 4);
		if (pile->a < cut)
		{
			pb(pile);
			write(1, "pb\n", 3);
		}
	}
	qs_oA(pile, cut, max);
	qs_oB(pile, min, cut);
}

void	qs_uB(t_pile *pile, int min, int max)
{
	int cut;
	int i;

	i = max-min;
	if (i <= 1)
	{
		rrb(pile);
		write(1, "rrb\n", 4);
		pa(pile);
		write(1, "pa\n", 3);
		return ; //TODO
	}
	cut = min + i / 2;
	while (i--)
	{
		rrb(pile);
		write(1, "rrb\n", 4);
		if (pile->b >= cut)
		{
			pa(pile);
			write(1, "pa\n", 3);
		}
	}
	qs_oA(pile, cut, max);
	qs_oB(pile, min, cut);
}

void	qs_oA(t_pile *pile, int min, int max)
{
	int cut;
	int i;

	i = max-min;
	if (i <= 1)
		return ; //TODO
	cut = min + i / 2;
	while (i--)
	{
		if (pile->a < cut)
		{
			pb(pile);
			write(1, "pb\n", 3);
		}
		else
		{
			ra(pile);
			write(1, "ra\n", 3);
		}
	}
	qs_uA(pile, cut, max);
	qs_oB(pile, min, cut);
}

void	qs_oB(t_pile *pile, int min, int max)
{
	int cut;
	int i;

	i = max-min;
	if (i <= 1)
	{
		pa(pile);
		write(1, "pa\n", 3);
		return ; //TODO
	}
	cut = min + i / 2;
	while (i--)
	{
		if (pile->b < cut)
		{
			rb(pile);
			write(1, "rb\n", 3);
		}
		else
		{
			pa(pile);
			write(1, "pa\n", 3);
		}
	}
	qs_oA(pile, cut, max);
	qs_uB(pile, min, cut);
}
