/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over6_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:07:41 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/11 13:53:35 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_testprint_st(st);
void	ft_over6_sort(t_node **st, t_sortinfo *infos, int lst_end)
{
	t_sortinfo	infos_next;

	if (ft_sorted(st[A]))
		return ;
	if (infos->len <= 3)
	{
		if (infos->len == 3)
			ft_3num_sort(st);
		if (infos->len == 2)
			ft_2num_sort(st);
		while (st[B]->prev->idx > lst_end / 2 && \
			st[B]->next->idx >= lst_end / 2)
			ft_op_call(st, RRB);
		return ;
	}
	ft_setinfos(&infos_next, B, infos->min, infos->max);
	ft_partition_to_b(st, &infos_next, 0);
	ft_setinfos(&infos_next, B, infos->pivot + 1, lst_end);
	ft_over6_sort(st, &infos_next, lst_end);
	ft_sort_to_a(st, lst_end);
	while (st[A]->prev->idx != lst_end)
		ft_op_call(st, RRA);
}

void	ft_sort_to_a(t_node **st, int lst_end)
{
	t_node	*tmp;

	tmp = st[B]->next;
	while (tmp)
	{
		if (tmp->idx < tmp->next->idx && tmp->idx > tmp->next->next->idx)
			ft_op_call(st, SB);
		tmp = st[B]->next;
		while (st[A]->next->idx < tmp->idx)
			ft_op_call(st, RA);
		while (st[A]->prev->idx > tmp->idx && st[A]->prev->idx != lst_end)
			ft_op_call(st, RRA);
		ft_op_call(st, PA);
		tmp = st[B]->next;
	}
}
