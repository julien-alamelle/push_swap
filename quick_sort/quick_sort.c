#include "quick_sort.h"
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
void	pp(t_pile *p)
{
	return;
	int	*pos = get_pos(p);
	if(!pos) return;
	for (int i = 0; i < p->n + 1; ++i)
		printf("%2d ", pos[i]);
	printf("\n");
	free(pos);
}

void	quick_sort(t_pile *pile)
{
	int cut;
	int i;

	i = pile->n;
	if (i <= 1)
		return ; //TODO
	cut = i / 2;
	while (i--)
	{
	pp(pile);
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
	qs_A(pile, cut, pile->n);
	qs_B(pile, 0, cut);
}

void	qs_A(t_pile *pile, int min, int max)
{
	int cut;
	int i;

	i = max-min;
	if (i <= 1)
		return ; //TODO
	cut = min + i / 2;
	while (i--)
	{
	pp(pile);
//	dprintf(2, "%d %d\n", cut, pile->a);
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
	qs_A(pile, cut, max);
	qs_oB(pile, min, cut);
}

void	qs_B(t_pile *pile, int min, int max)
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
	qs_B(pile, min, cut);
}
