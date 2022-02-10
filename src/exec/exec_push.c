/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:31:48 by jalamell          #+#    #+#             */
/*   Updated: 2022/02/10 18:32:35 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>

int	exec_pa(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			pa(p, 0);
			return (0);
		}
	}
	return (1);
}

int	exec_pb(t_pile *p)
{
	char	c;

	if (read(0, &c, 1))
	{
		if (c == '\n')
		{
			pb(p, 0);
			return (0);
		}
	}
	return (1);
}
