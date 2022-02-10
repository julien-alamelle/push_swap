/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:31:37 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/10 18:32:44 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>

int	exec_rra(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rra(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rrb(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rrb(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_rrr(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			rrr(p, 0);
			return (0);
		}
	}
	return (1);
}
