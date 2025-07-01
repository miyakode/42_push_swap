/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:24:56 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 15:55:50 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_arg_charcount(int ac, char **av)
{
	int		len;
	char	*p;

	len = 0;
	while (--ac)
	{
		p = av[ac];
		while (*p++)
			len++;
	}
	return (len);
}

int	ft_issorted(t_node *st)
{
	t_node	*tmp;

	tmp = st->next;
	if (!tmp)
		return (0);
	if (tmp && tmp->next == st)
		return (1);
	while (tmp != st)
	{
		if ((tmp->n > tmp->next->n && tmp->next != st))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_onlyspace(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isspace(*s) || !*s)
			return (0);
		s++;
	}
	return (1);
}

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
