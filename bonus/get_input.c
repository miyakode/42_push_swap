/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:54:27 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/07 22:39:21 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_input(t_node **st, int first)
{
	char	*line;
	int		op;
	int		result;

	line = get_next_line(0);
	if (first && ft_issorted(st[A]) && line)
		return (free(line), KO);
	else if (!line)
		return (0);
	op = ft_check_line(line);
	if (op == ERR)
		return (free(line), ERROR);
	else if (ft_op_call(st, op) == ERR)
		return (free(line), KO);
	result = ft_get_input(st, 0);
	free(line);
	return (result);
}

int	ft_check_line(char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		return (SA);
	else if (!ft_strncmp(line, "sb\n", 4))
		return (SB);
	else if (!ft_strncmp(line, "ss\n", 4))
		return (SS);
	else if (!ft_strncmp(line, "pa\n", 4))
		return (PA);
	else if (!ft_strncmp(line, "pb\n", 4))
		return (PB);
	else if (!ft_strncmp(line, "ra\n", 4))
		return (RA);
	else if (!ft_strncmp(line, "rb\n", 4))
		return (RB);
	else if (!ft_strncmp(line, "rr\n", 4))
		return (RR);
	else if (!ft_strncmp(line, "rra\n", 5))
		return (RRA);
	else if (!ft_strncmp(line, "rrb\n", 5))
		return (RRB);
	else if (!ft_strncmp(line, "rrr\n", 5))
		return (RRR);
	return (ERR);
}
