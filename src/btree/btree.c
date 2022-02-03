/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:17:42 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 16:21:05 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

t_tree	*tree_init(int *data)
{
	t_tree	*ret;

	ret = malloc(sizeof(t_tree));
	if (ret)
	{
		ret->data = data;
		ret->smaller = 0;
		ret->biger = 0;
	}
	return (ret);
}

t_tree	*tree_del(t_tree *t)
{
	if (t)
	{
		free(t->data);
		tree_del(t->smaller);
		tree_del(t->biger);
		free(t);
	}
	return (0);
}

static int	tab_cmp(int *t1, int *t2, int n)
{
	int	c;

	c = 0;
	while (!c && n--)
		c = t1[n] - t2[n];
	return (c);
}

int	tree_add(t_tree **t, int *data, int size)
{
	int	cmp;

	if (!t)
		return (1);
	while (*t)
	{
		cmp = tab_cmp(data, (*t)->data, size);
		if (!cmp)
		{
			free(data);
			return (1);
		}
		if (cmp > 0)
			t = &((*t)->biger);
		else
			t = &((*t)->smaller);
	}
	*t = tree_init(data);
	return (0);
}
