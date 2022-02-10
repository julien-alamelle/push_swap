/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:59:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 17:09:49 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H

typedef struct s_pile
{
	int	n;
	int	*u;
	int	*o;
	int	a;
	int	b;
}	t_pile;

/*********************/
/* info (pile_cut) : */
/* 0 = ua            */
/* 1 = oa            */
/* 2 = ub            */
/* 3 = ob            */
/*********************/

t_pile	*pile_init(int ac, char **av);
t_pile	*pile_copy(t_pile *p);
t_pile	*pile_del(t_pile *p);
t_pile	*pile_cut(t_pile *p, int min, int max, int info);
int		pile_is_sort(t_pile *p);
void	fill_pos(t_pile *p, int *ret);
int		*get_pos(t_pile *p);
t_pile	*sa(t_pile *p, char print);
t_pile	*sb(t_pile *p, char print);
t_pile	*ss(t_pile *p, char print);
t_pile	*pa(t_pile *p, char print);
t_pile	*pb(t_pile *p, char print);
t_pile	*ra(t_pile *p, char print);
t_pile	*rb(t_pile *p, char print);
t_pile	*rr(t_pile *p, char print);
t_pile	*rra(t_pile *p, char print);
t_pile	*rrb(t_pile *p, char print);
t_pile	*rrr(t_pile *p, char print);

#endif
