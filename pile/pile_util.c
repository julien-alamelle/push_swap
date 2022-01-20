#include "pile.h"
#include <stdlib.h>

static void	copy_content(t_pile *src, t_pile *dst)
{
	int	i;

	dst->n = src->n;
	dst->a = src->a;
	dst->b = src->b;
	dst->last_op = src->last_op;
	i = -1;
	while (++i < src->n)
	{
		dst->u[i] = src->u[i];
		dst->o[i] = src->o[i];
	}
}

t_pile	*pile_copy(t_pile *p)
{
	t_pile	*ret;

	if (!p)
		return (0);
	ret = malloc(sizeof(t_pile));
	if (ret)
	{
		ret->u = malloc(p->n * sizeof(int));
		ret->o = malloc(p->n * sizeof(int));
		if (ret->u && ret->o)
			copy_content(p, ret);
		else
			ret = pile_del(ret);
	}
	return (ret);
}

t_pile	*pile_del(t_pile *p)
{
	if (p)
	{
		if (p->u)
			free(p->u);
		if (p->o)
			free(p->o);
		free(p);
	}
	return (0);
}

#include <stdio.h>

int	*get_pos(t_pile *p)
{
	int	*ret;
	int	i;
	int	cur;

	ret = malloc((p->n + 1) * sizeof(int));
	if (!ret)
		return (ret);
	i = 0;
	cur = p->a;
//	printf("%2d init\n", cur);
	if (cur != -1)
	{
		ret[i++] = cur;
		while ((p->u)[cur] != p->a)
		{
//	printf("%2d\n", cur);
			cur = (p->u)[cur];
			ret[i++] = cur;
		}
	}
//	printf("pa done\n");
	ret[i++] = -1;
	cur = p->b;
//	printf("%2d init\n", cur);
	if (cur == -1)
		return (ret);
	ret[i++] = cur;
	while ((p->u)[cur] != p->b)
	{
//	printf("%2d\n", cur);
		cur = (p->u)[cur];
		ret[i++] = cur;
	}
//	printf("pb done\n");
	return (ret);
}
