/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:33:26 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/08 17:00:49 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_swap(t_node *st)
{
	t_node	*tmp;

	if (!st->next || st->next->next == st)
		return (ERR);
	tmp = st->next;
	st->next = tmp->next;
	tmp->next = tmp->next->next;
	st->next->next = tmp;
	tmp->next->prev = tmp;
	tmp->prev = st->next;
	st->next->prev = st;
	return (0);
}

int	ft_rotate(t_node *st)
{
	t_node	*tmp;

	if (!(st->next))
		return (ERR);
	else if (st->next->next == st)
		return (0);
	tmp = st->next;
	st->next = tmp->next;
	tmp->next = st;
	st->prev->next = tmp;
	tmp->prev = st->prev;
	st->prev = tmp;
	st->next->prev = st;
	return (0);
}

int	ft_reverse(t_node *st)
{
	t_node	*tmp;

	if (!(st->next))
		return (ERR);
	else if (st->next->next == st)
		return (0);
	tmp = st->prev;
	tmp->next = st->next;
	st->next = tmp;
	tmp->prev->next = st;
	st->prev = tmp->prev;
	tmp->prev = st;
	tmp->next->prev = tmp;
	return (0);
}

int	ft_push(t_node *from, t_node *to)
{
	t_node	*tmp;

	if (!from->next)
		return (ERR);
	tmp = from->next;
	if (!to->next)
	{
		to->next = tmp;
		to->prev = tmp;
		from->next = tmp->next;
		tmp->next = to;
		from->next->prev = from;
	}
	else
	{
		from->next = tmp->next;
		from->next->prev = from;
		tmp->next = to->next;
		to->next = tmp;
		tmp->next->prev = tmp;
	}
	tmp->prev = to;
	if (from == from->next)
		from->next = NULL;
	return (0);
}
