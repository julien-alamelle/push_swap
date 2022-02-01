/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:59:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/01/28 19:10:13 by jalamell         ###   ########lyon.fr   */
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

t_pile	*pile_init(int ac, char **av);
t_pile	*pile_copy(t_pile *p);
t_pile	*pile_del(t_pile *p);
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
