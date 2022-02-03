/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:17:29 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 16:21:36 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

typedef struct s_tree
{
	int				*data;
	struct s_tree	*smaller;
	struct s_tree	*biger;
}	t_tree;

t_tree	*tree_init(int *data);
t_tree	*tree_del(t_tree *t);
int		tree_add(t_tree **t, int *data, int size);

#endif
