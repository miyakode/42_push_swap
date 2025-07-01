/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:19:37 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/05 23:09:40 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_stack(t_node **stack)
{
	int			lst_len;
	int			err;
	t_sortinfo	infos;

	err = 0;
	lst_len = ft_lstlen(stack[A]);
	if (lst_len == 1 || ft_sorted(stack[A]))
		return (0);
	else if (lst_len == 2)
		err = ft_2num_sort(stack);
	else if (lst_len == 3)
		err = ft_3num_sort(stack);
	else
	{
		if (ft_compressor(stack[A], lst_len) == ERR)
			return (ERR);
		ft_setinfos(&infos, A, 1, lst_len);
		if (lst_len < 7)
			ft_6num_sort(stack, lst_len);
		else
			ft_over6_sort(stack, &infos, lst_len);
	}
	if (err == ERR)
		return (ERR);
	return (0);
}

int	ft_2num_sort(t_node **st)
{
	if (st[A]->next->n == st[A]->next->next->n)
		return (ERR);
	if (st[A]->next->n > st[A]->next->next->n)
		ft_op_call(st, SA);
	return (0);
}

int	ft_3num_sort(t_node **st)
{
	t_node	*mid;

	if (!ft_check_stacklen(st[A], 3))
		return (ft_putstr_fd("not3\n", 1), ERR);
	mid = st[A]->next->next;
	if (mid->n == mid->prev->n || mid->n == mid->next->n || \
		mid->prev->n == mid->next->n)
		return (ERR);
	if (mid->prev->n > mid->n && mid->prev->n > mid->next->n)
		ft_op_call(st, RA);
	else if (mid->prev->n < mid->n)
		if (!(mid->n < mid->next->n))
			ft_op_call(st, RRA);
	mid = st[A]->next->next;
	if (mid->prev->n > mid->n)
		ft_op_call(st, SA);
	return (0);
}

int	ft_3num_sort_rev(t_node **st)
{
	t_node	*mid;

	mid = st[B]->next->next;
	if (mid->n == mid->prev->n || mid->n == mid->next->n || \
		mid->prev->n == mid->next->n)
		return (ERR);
	if (mid->prev->n < mid->n && mid->prev->n < mid->next->n)
		ft_op_call(st, RB);
	else if (mid->prev->n > mid->n)
		if (!(mid->n > mid->next->n))
			ft_op_call(st, RRB);
	mid = st[B]->next->next;
	if (mid->prev->n < mid->n)
		ft_op_call(st, SB);
	return (0);
}

void	ft_6num_sort(t_node **st, int len)
{
	t_node	*tmp;
	int		pb_count;

	tmp = st[A]->next;
	pb_count = 0;
	len -= 3;
	while (tmp && pb_count != len)
	{
		if (tmp->idx <= len)
		{
			ft_op_call(st, PB);
			pb_count++;
		}
		else
			ft_op_call(st, RA);
		tmp = st[A]->next;
	}
	ft_3num_sort(st);
	if (pb_count == 3)
		ft_3num_sort_rev(st);
	else if (pb_count == 2 && st[B]->next->idx < st[B]->next->next->idx)
		ft_op_call(st, SB);
	while (pb_count--)
		ft_op_call(st, PA);
}
