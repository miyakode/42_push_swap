/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcall_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:19:12 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 16:18:18 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_op_call(t_node **st, int op)
{
	int	err;

	err = 0;
	if (op == PA)
		err = ft_push(st[B], st[A]);
	else if (op == PB)
		err = ft_push(st[A], st[B]);
	else if (op == SA || op == SB)
		err = ft_swap(st[op - SA]);
	else if (op == RA || op == RB)
		err = ft_rotate(st[op - RA]);
	else if (op == RRA || op == RRB)
		err = ft_reverse(st[op - RRA]);
	else if (op == SS || op == RR || op == RRR)
		err = ft_op_double(st, op);
	if (err == ERR)
		return (ERR);
	return (0);
}

int	ft_op_double(t_node **st, int op)
{
	int	opret;

	opret = 0;
	if (op == SS)
	{
		opret = ft_swap(st[A]);
		if (opret != ERR)
			opret = ft_swap(st[B]);
	}
	else if (op == RR)
	{
		opret = ft_rotate(st[A]);
		if (opret != ERR)
			opret = ft_rotate(st[B]);
	}
	else if (op == RRR)
	{
		opret = ft_reverse(st[A]);
		if (opret != ERR)
			opret = ft_reverse(st[B]);
	}
	return (opret);
}
