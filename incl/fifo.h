/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:37:41 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/03 16:14:21 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H

typedef struct s_fifo_cell
{
	void				*data;
	struct s_fifo_cell	*next;
}	t_fifo_cell;

typedef struct s_fifo
{
	t_fifo_cell	*first;
	t_fifo_cell	*last;
	void		(*del)(void *);
}	t_fifo;

t_fifo	*fifo_init(void (*del)(void *));
t_fifo	*fifo_del(t_fifo *f);
void	*fifo_get(t_fifo *f);
void	fifo_add(t_fifo *f, void *data);

#endif
