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

# include <stdio.h>
static void	test_all_move2(t_pile_lim *new, t_pile_lim *cur, t_fifo *todo,
	t_tree **done)
{
	new = lim_ra(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
	new = lim_rb(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
	new = lim_rr(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
	new = lim_rra(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
	new = lim_rrb(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
	new = lim_rrr(cur, 0);
	if (new)
		if (!tree_add(done, lim_get_pos(new), new->pile->n + 1))
			fifo_add(todo, new);
}

static t_pile_lim	test_all_move(t_pile_lim *cur, t_fifo *f, t_tree **t)
{
	t_pile_lim	*new;

	new = lim_sa(cur, 0);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		new = fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_sb(cur, 0);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		new = fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_ss(cur, 0);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		new = fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_pa(cur, 0);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		new = fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	new = lim_pb(cur, 0);
	if (pile_lim_is_sort(new))
		return (new);
	if (new)
		new = fifo_add(f, new, tree_add(t, lim_get_pos(new), new->pile->n + 1));
	return (test_all_move2(new, cur, todo, done));
}

int	perfect_sort(t_pile *p, int min, int max, int info)
{
dprintf(2,"in\n");
	t_fifo		*todo;
	t_tree		*done;
	t_pile_lim	*cur;

	cur = pile_lim_init(p, min, max, info);
dprintf(2,"%d %d %d %d\n",cur->ua,cur->ub,cur->oa,cur->ob);
	done = tree_init(lim_get_pos(cur));
	todo = fifo_init((void *(*)(void *))pile_lim_del);
dprintf(2,"loop\n");
	while (cur)
	{
		if (pile_is_sort(cur->pile))
		{
dprintf(2,"sort\n");
			tree_del(done);
			fifo_del(todo);
			pile_lim_del(cur);
dprintf(2,"clear\n");
			return (1);
		}
dprintf(2,"test\n");
		test_all_move(cur, todo, &done);
dprintf(2,"del\n");
		pile_lim_del(cur);
dprintf(2,"get\n");
		cur = fifo_get(todo);
	}
dprintf(2,"out\n");
	tree_del(done);
	fifo_del(todo);
dprintf(2,"clear\n");
	return (0);
}
