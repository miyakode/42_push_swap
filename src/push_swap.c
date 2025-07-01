/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:29:41 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 16:46:54 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	//ft_testprint_st(stack);
	//ft_test_op(stack);
int	main(int ac, char **av)
{
	t_node	*stack[2];

	if (ac == 1)
		return (0);
	stack[A] = NULL;
	stack[B] = NULL;
	ft_create_stack(stack, A);
	if (!stack[A])
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_create_stack(stack, B);
	if (!stack[B])
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	if (ft_create_lst(stack[A], ac, av) == ERR)
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	if (!stack[A])
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	if (ft_sort_stack(stack) == ERR)
		return (ft_free_stacks(stack), ft_putstr_fd("Error\n", 2), 1);
	ft_free_stacks(stack);
	return (0);
}

void	ft_create_stack(t_node **stack, int idx)
{
	stack[idx] = ft_calloc(sizeof(t_node), 1);
	if (!stack[idx])
		return ;
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
