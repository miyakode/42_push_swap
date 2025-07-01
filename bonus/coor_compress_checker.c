/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_compress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:12:11 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/03 16:14:20 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compressor(t_node *stA, int len)
{
	t_node	**adr_lst;

	adr_lst = ft_calloc(len, sizeof(t_node *));
	if (!adr_lst)
		return (ERR);
	ft_create_adr_lst(stA, len, adr_lst);
	ft_quicksort_comp(adr_lst, 0, len - 1);
	while (--len >= 0)
	{
		if (len > 0 && adr_lst[len]->n == adr_lst[len - 1]->n)
			return (free(adr_lst), ERR);
		adr_lst[len]->idx = len + 1;
	}
	free(adr_lst);
	return (0);
}

void	ft_quicksort_comp(t_node **adr_lst, int start, int end)
{
	unsigned int	p_idx;

	if (end - start < 1)
		return ;
	if (end - start == 1)
	{
		if ((adr_lst[start])->n > (adr_lst[end])->n)
			ft_swap_adr(adr_lst, start, end);
		return ;
	}
	p_idx = ft_random_num(end - start + 1) + start;
	p_idx = ft_partition(adr_lst, start, end, p_idx);
	ft_quicksort_comp(adr_lst, start, p_idx - 1);
	ft_quicksort_comp(adr_lst, p_idx + 1, end);
}

unsigned int	ft_partition(t_node **lst, int start, int end, \
unsigned int p_idx)
{
	int		pivot;

	pivot = (lst[p_idx])->n;
	ft_swap_adr(lst, p_idx, end);
	p_idx = end--;
	while (start != end)
	{
		while ((lst[start])->n < pivot)
			start++;
		if (lst[start]->n == pivot && start == (int)p_idx)
			break ;
		while ((lst[end])->n > pivot && start < end)
			end--;
		if (start != end)
			ft_swap_adr(lst, start, end);
	}
	if (start == end)
		ft_swap_adr(lst, start, p_idx);
	return (start);
}

void	ft_swap_adr(t_node **lst, int idx1, int idx2)
{
	t_node		*tmp;

	tmp = lst[idx1];
	lst[idx1] = lst[idx2];
	lst[idx2] = tmp;
}

void	ft_create_adr_lst(t_node *stA, int len, t_node **lst)
{
	int	i;

	i = 0;
	stA = stA->next;
	while (i < len)
	{
		lst[i++] = stA;
		if (stA->next)
			stA = stA->next;
	}
}
