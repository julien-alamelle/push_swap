#ifndef BTREE_H
# define BTREE_H

typedef struct s_tree
{
	int	*data;
	t_tree	*smaller;
	t_tree	*biger;
}	t_tree;

t_tree	*tree_init(int *data);
t_tree	*tree_del(t_tree *t);
int	tree_add(t_tree **t, int *data, int size);

#endif
