/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:22:04 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/04 19:11:58 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen(t_node *stack)
{
	t_node	*tmp;
	int		len;

	tmp = stack;
	len = 0;
	while (tmp->next && tmp->next != stack)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_free_lst(t_node *stack, t_node *tmp)
{
	if (!tmp)
	{
		free(stack);
		return ;
	}
	if (tmp == stack)
	{
		free(tmp);
		return ;
	}
	ft_free_lst(stack, tmp->next);
	free(tmp);
}

void	ft_free_arglst(char **lst, int idx)
{
	if (!lst)
		return ;
	if (idx < 0)
	{
		free(lst);
		return ;
	}
	free(lst[idx]);
	ft_free_arglst(lst, idx - 1);
}

int	ft_sorted(t_node *st)
{
	t_node	*tmp;

	tmp = st->next;
	if (!tmp)
		return (0);
	while (tmp != st)
	{
		if ((tmp->n > tmp->next->n && tmp->next != st) || \
			tmp->n == tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_stacklen(t_node *st, int len)
{
	t_node	*tmp;

	if (!st->next && !len)
		return (1);
	else if ((!st->next && len) || (st->next && !len))
		return (0);
	tmp = st;
	while (tmp->next != st && len)
	{
		tmp = tmp->next;
		len--;
	}
	if (tmp->next == st && !len)
		return (1);
	else
		return (0);
}
