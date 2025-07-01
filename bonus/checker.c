/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:06:05 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 16:36:25 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

	//ft_test_op(stack);
int	main(int ac, char **av)
{
	t_node	*stack[2];
	int		result;

	result = 0;
	if (ac == 1)
		return (0);
	stack[A] = NULL;
	stack[B] = NULL;
	if (ft_create_stack(stack) == ERR)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ft_create_lst(stack[A], ac, av) == ERR)
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	if (ft_compressor(stack[A], ft_lstlen(stack[A])) == ERR)
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	result = ft_get_input(stack, 1);
	if (result == ERR)
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	else if (result == KO)
		return (ft_free_stacks(stack), ft_putstr_fd("KO\n", 1), 1);
	if (ft_issorted(stack[A]) && !stack[B]->next)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stacks(stack);
	return (0);
}

int	ft_create_stack(t_node **st)
{
	st[A] = ft_calloc(sizeof(t_node), 1);
	if (!st[A])
		return (ERR);
	st[B] = ft_calloc(sizeof(t_node), 1);
	if (!st[B])
		return (free(st[A]), ERR);
	return (0);
}

void	ft_free_stacks(t_node **stack)
{
	if (!stack)
		return ;
	if (stack[A])
		ft_free_lst(stack[A], stack[A]->next);
	if (stack[B])
		ft_free_lst(stack[B], stack[B]->next);
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
