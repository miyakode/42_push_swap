/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:14:32 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/07 21:53:54 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

unsigned int	ft_random_num(int len)
{
	unsigned int	n;

	n = 123456789 + len;
	n ^= n << 13;
	n ^= n >> 17;
	n ^= n << 5;
	n = n % len;
	return (n);
}

/*
int	ft_double_idx(t_node *stA)
{
	t_node	*tmp;

	tmp = stA->next;
	while (tmp && tmp != stA)
	{
		if (tmp->idx == tmp->next->idx)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
*/

void	ft_setinfos(t_sortinfo *infos, int from, int min, int max)
{
	infos->min = min;
	infos->max = max;
	infos->from = from;
	infos->len = max - min + 1;
	infos->pivot = infos->len / 2 + (infos->len % 2) + min - 1;
	infos->pivot2 = infos->pivot - ((infos->pivot - min + 1) / 2);
	infos->pivot2 += ((infos->pivot - min + 1) % 2);
	if (from == A)
		infos->to = B;
	else
		infos->to = A;
}
