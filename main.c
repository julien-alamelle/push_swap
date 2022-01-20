#include "pile.h"
#include "quick_sort.h"

int	main(int ac, char **av)
{
	t_pile	*pile;

	pile = pile_init(ac - 1, av + 1);
	if (!pile)
		return (0);
	quick_sort(pile);
	pile_del(pile);
	return (0);
}
