/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:31:30 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/10 18:32:49 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>

int	exec_sa(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			sa(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_sb(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			sb(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_ss(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			ss(p, 0);
			return (0);
		}
	}
	return (1);
}
