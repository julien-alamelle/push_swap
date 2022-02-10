/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:04 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/10 18:33:09 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "pile.h"

void	exec_stdin(t_pile *p);
int		exec_pa(t_pile *p);
int		exec_pb(t_pile *p);
int		exec_sa(t_pile *p);
int		exec_sb(t_pile *p);
int		exec_ss(t_pile *p);
int		exec_ra(t_pile *p);
int		exec_rb(t_pile *p);
int		exec_rr(t_pile *p);
int		exec_rra(t_pile *p);
int		exec_rrb(t_pile *p);
int		exec_rrr(t_pile *p);

#endif
