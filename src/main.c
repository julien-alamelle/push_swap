/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:44 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:17:42 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"
#include "quick_sort.h"

int	main(int ac, char **av)
{
	t_pile	*pile;

	pile = pile_init(ac - 1, av + 1);
	if (!pile)
		return (0);
	if (!pile_is_sort(pile))
		quick_sort(pile);
	pile_del(pile);
	return (0);
}
