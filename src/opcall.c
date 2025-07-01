/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:51:36 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/07 22:10:01 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_call(t_node **st, int op)
{
	if (op == PA)
		ft_push(st[B], st[A]);
	else if (op == PB)
		ft_push(st[A], st[B]);
	else if (op == SA)
		ft_swap(st[A]);
	else if (op == SB)
		ft_swap(st[B]);
	else if (op == RA)
		ft_rotate(st[A]);
	else if (op == RB)
		ft_rotate(st[B]);
	else if (op == RRA)
		ft_reverse(st[A]);
	else if (op == RRB)
		ft_reverse(st[B]);
	else if (op == SS || op == RR || op == RRR)
		ft_op_double(st, op);
	ft_print_op(op);
}

void	ft_op_double(t_node **st, int op)
{
	if (!st[A]->next || !st[B]->next)
		return ;
	if (op == SS)
	{
		if (st[A]->next->next == st[A] || st[B]->next->next == st[B])
			return ;
		ft_swap(st[A]);
		ft_swap(st[B]);
		return ;
	}
	if (st[A]->next == st[A]->prev || st[B]->next == st[B]->prev)
		return ;
	if (op == RR)
	{
		ft_rotate(st[A]);
		ft_rotate(st[B]);
	}
	else if (op == RRR)
	{
		ft_reverse(st[A]);
		ft_reverse(st[B]);
	}
}

void	ft_print_op(int op)
{
	if (op == SA || op == SB)
		write(1, "s", 1);
	else if (op == SS)
		write(1, "ss", 2);
	else if (op == PA || op == PB)
		write(1, "p", 1);
	else if (op == RA || op == RB || op == RR)
		write(1, "r", 1);
	else if (op == RRA || op == RRB || op == RRR)
		write(1, "rr", 2);
	if (op == SA || op == PA || op == RA || op == RRA)
		write(1, "a", 1);
	else if (op == SB || op == PB || op == RB || op == RRB)
		write(1, "b", 1);
	else if (op == RR || op == RRR)
		write(1, "r", 1);
	write(1, "\n", 1);
}
