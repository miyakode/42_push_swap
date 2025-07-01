/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_partition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:39:20 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/11 13:55:11 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_partition_to_b(t_node **st, t_sortinfo *infos, int pb_count)
{
	t_node		*tmp;
	t_sortinfo	infos_next;

	tmp = st[A]->next;
	while (tmp && tmp != st[A] && pb_count < infos->len / 2 + (infos->len % 2))
	{
		if (tmp->idx > infos->pivot)
			ft_op_call(st, RA);
		else if (tmp->idx <= infos->pivot)
		{
			ft_op_call(st, PB);
			pb_count++;
			if (tmp->idx > infos->pivot2)
				ft_op_call(st, RB);
		}
		tmp = st[A]->next;
	}
	if (infos->len <= 16 && infos->min != 1)
		while (infos->min <= st[B]->prev->idx && st[B]->prev->idx <= infos->max)
			ft_op_call(st, RRB);
	ft_setinfos(&infos_next, B, infos->min, infos->pivot2);
	ft_part_top(st, &infos_next);
	ft_setinfos(&infos_next, B, infos->pivot2 + 1, infos->pivot);
	ft_part_bot(st, &infos_next);
}

void	ft_part_top(t_node **st, t_sortinfo *infos)
{
	t_node		*tmp;
	t_sortinfo	infos_next;

	tmp = st[infos->from]->next;
	if (infos->len <= 16)
		return ;
	while (infos->min <= tmp->idx && tmp->idx <= infos->max)
	{
		if ((infos->from == A && tmp->idx <= infos->pivot) || \
			(infos->from == B && tmp->idx > infos->pivot))
			ft_op_call(st, PA + infos->to);
		else
			ft_op_call(st, RA + infos->from);
		tmp = st[infos->from]->next;
	}
	ft_setinfos(&infos_next, infos->from, infos->min, infos->pivot);
	if (infos->from == A)
		ft_setinfos(&infos_next, infos->from, infos->pivot + 1, infos->max);
	ft_part_bot(st, &infos_next);
	ft_setinfos(&infos_next, infos->to, infos->pivot + 1, infos->max);
	if (infos->from == A)
		ft_setinfos(&infos_next, infos->to, infos->min, infos->pivot);
	ft_part_top(st, &infos_next);
	ft_setinfos(&infos_next, infos->to, infos->min, infos->max);
	ft_back_part(st, &infos_next, 0);
}

void	ft_part_bot(t_node **st, t_sortinfo *infos)
{
	t_node		*tmp;
	t_sortinfo	infos_next;

	if (infos->len <= 2)
		return ;
	tmp = st[infos->from]->prev;
	while (infos->min <= tmp->idx && tmp->idx <= infos->max)
	{
		ft_op_call(st, RRA + infos->from);
		if (infos->from == B && tmp->idx > infos->pivot)
			ft_op_call(st, PA);
		if (infos->from == A && tmp->idx <= infos->pivot)
			ft_op_call(st, PB);
		tmp = st[infos->from]->prev;
	}
	ft_setinfos(&infos_next, infos->from, infos->min, infos->pivot);
	ft_part_top(st, &infos_next);
	ft_setinfos(&infos_next, infos->to, infos->pivot + 1, infos->max);
	ft_part_top(st, &infos_next);
	ft_setinfos(&infos_next, infos->to, infos->min, infos->max);
	ft_back_part(st, &infos_next, 1);
}

void	ft_back_part(t_node **st, t_sortinfo *infos, int back_to_bot)
{
	t_node	*tmp;

	tmp = st[infos->to]->prev;
	if (!back_to_bot)
	{
		while (tmp && infos->min <= tmp->idx && tmp->idx <= infos->max)
		{
			ft_op_call(st, RRA + infos->to);
			tmp = st[infos->to]->prev;
		}
	}
	tmp = st[infos->from]->next;
	if (infos->to == B)
	{
		while (tmp && infos->min <= tmp->idx && tmp->idx <= infos->max)
		{
			tmp = st[infos->from]->next;
			ft_op_call(st, PA + infos->to);
			tmp = st[infos->from]->next;
		}
	}
}
