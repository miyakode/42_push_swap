/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:33:26 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/07 21:52:49 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *st)
{
	t_node	*tmp;

	if (!st->next || st->next->next == st)
		return ;
	tmp = st->next;
	st->next = tmp->next;
	tmp->next = tmp->next->next;
	st->next->next = tmp;
	tmp->next->prev = tmp;
	tmp->prev = st->next;
	st->next->prev = st;
}

void	ft_rotate(t_node *st)
{
	t_node	*tmp;

	if (!(st->next))
		return ;
	else if (st->next->next == st)
		return ;
	tmp = st->next;
	st->next = tmp->next;
	tmp->next = st;
	st->prev->next = tmp;
	tmp->prev = st->prev;
	st->prev = tmp;
	st->next->prev = st;
}

void	ft_reverse(t_node *st)
{
	t_node	*tmp;

	if (!(st->next))
		return ;
	else if (st->next->next == st)
		return ;
	tmp = st->prev;
	tmp->next = st->next;
	st->next = tmp;
	tmp->prev->next = st;
	st->prev = tmp->prev;
	tmp->prev = st;
	tmp->next->prev = tmp;
}

void	ft_push(t_node *from, t_node *to)
{
	t_node	*tmp;

	if (!from->next)
		return ;
	tmp = from->next;
	if (!to->next)
	{
		to->next = tmp;
		to->prev = tmp;
		from->next = tmp->next;
		tmp->next = to;
		from->next->prev = from;
		tmp->prev = to;
	}
	else
	{
		from->next = tmp->next;
		from->next->prev = from;
		tmp->next = to->next;
		to->next = tmp;
		tmp->next->prev = tmp;
		tmp->prev = to;
	}
	if (from == from->next)
		from->next = NULL;
}
