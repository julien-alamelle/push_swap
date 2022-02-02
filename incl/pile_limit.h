/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_limit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:42:57 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/01 17:25:35 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_LIMIT_H
# define PILE_LIMIT_H

# include "pile.h"

/**********************************************************/
/* last_op :                                              */
/*   0 : nothing                                          */
/*   0 : pb   conflict pa                                 */
/*   1 : pa   conflict pb, nothing                        */
/*   2 : sa   conflict sa, sb, ss                         */
/*   2 : sb   conflict sa, sb, ss                         */
/*   2 : ss   conflict sa, sb, ss                         */
/*   4 : ra   conflict rb, rra, rrr   not after rr, rrb   */
/*   8 : rb   conflict ra, rrb, rrr   not after rr, rra   */
/*  16 : rr   conflict rra, rrb, rrr                      */
/*  32 : rra  conflict ra, rr, rrb                        */
/*  64 : rrb  conflict rb, rr, rra                        */
/* 128 : rrr  conflict ra, rb, rr     not after rra, rrb  */
/**********************************************************/

typedef struct s_pile_lim
{
	unsigned char	last_op;
	int				ua;
	int				ub;
	int				oa;
	int				ob;
	t_pile			*pile;
}	t_pile_lim;

/**************************/
/* info (pile_lim_init) : */
/* 0 = ua                 */
/* 1 = oa                 */
/* 2 = ub                 */
/* 3 = ob                 */
/**************************/

t_pile_lim	*pile_lim_init(t_pile *p, int min, int max, int info);
t_pile_lim	*pile_lim_copy(t_pile_lim *p);
t_pile_lim	*pile_lim_del(t_pile_lim *p);
int			*lim_get_pos(t_pile_lim *p);
t_pile_lim	*lim_sa(t_pile_lim *p, char print);
t_pile_lim	*lim_sb(t_pile_lim *p, char print);
t_pile_lim	*lim_ss(t_pile_lim *p, char print);
t_pile_lim	*lim_pa(t_pile_lim *p, char print);
t_pile_lim	*lim_pb(t_pile_lim *p, char print);
t_pile_lim	*lim_ra(t_pile_lim *p, char print);
t_pile_lim	*lim_rb(t_pile_lim *p, char print);
t_pile_lim	*lim_rr(t_pile_lim *p, char print);
t_pile_lim	*lim_rra(t_pile_lim *p, char print);
t_pile_lim	*lim_rrb(t_pile_lim *p, char print);
t_pile_lim	*lim_rrr(t_pile_lim *p, char print);

#endif
