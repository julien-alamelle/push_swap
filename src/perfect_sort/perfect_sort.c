/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:29:23 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:15:25 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fifo.h"
#include "btree.h"
#include "pile.h"
#include "pile_limit.h"

static t_pile_lim	*test_all_move3(t_pile_lim *cur, t_fifo *f, t_tree **t)
{
	t_pile_lim	*new;

	new = lim_rr(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_rra(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_rrb(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_rrr(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	return (0);
}

static t_pile_lim	*test_all_move2(t_pile_lim *cur, t_fifo *f, t_tree **t)
{
	t_pile_lim	*new;

	new = lim_pa(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_pb(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_ra(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_rb(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	return (test_all_move3(cur, f, t));
}

static t_pile_lim	*test_all_move(t_pile_lim *cur, t_fifo *f, t_tree **t)
{
	t_pile_lim	*new;

	new = lim_sa(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_sb(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_ss(cur);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	return (test_all_move2(cur, f, t));
}

# include <stdio.h>
int	perfect_sort(t_pile *p, int min, int max, int info)
{
	t_fifo		*todo;
	t_tree		*done;
	t_pile_lim	*cur;
	t_pile_lim	*sorted;

//dprintf(2, "%p %3d %3d %d\n", p, min, max, info);
//dprintf(2, "pile_lim_init\n");
	cur = pile_lim_init(p, min, max, info);
//dprintf(2, "tree_init\n");
	done = tree_init(lim_get_pos(cur));
//dprintf(2, "fifo_init\n");
	todo = fifo_init((void *(*)(void *))pile_lim_del);
	while (cur)
	{
		sorted = test_all_move(cur, todo, &done);
		if (sorted)
		{
			tree_del(done);
			fifo_del(todo);
			pile_lim_exec(sorted, p);
			pile_lim_del(cur);
			pile_lim_del(sorted);
			return (1);
		}
		pile_lim_del(cur);
		cur = fifo_get(todo);
	}
	tree_del(done);
	fifo_del(todo);
	return (0);
}
