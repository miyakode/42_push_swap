/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:56:21 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 16:05:09 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_create_lst(t_node *stA, int ac, char **av)
{
	int		arg_cond;
	char	**args;
	int		arg_count;

	arg_cond = ft_valid_chars(ac, av, 0, 0);
	if (arg_cond == ERR)
		return (ERR);
	args = NULL;
	arg_count = 0;
	if (arg_cond == 1)
	{
		args = ft_split_args(ac, av);
		if (!args)
			return (ERR);
		while (args[arg_count])
			arg_count++;
		if (!ft_arg_to_lst(stA, stA, --arg_count, args))
			return (ft_free_arglst(args, arg_count), ERR);
	}
	else
		if (!ft_arg_to_lst(stA, stA, --ac, av))
			return (ft_free_arglst(args, arg_count), ERR);
	ft_free_arglst(args, arg_count);
	return (0);
}

int	ft_valid_chars(int ac, char **av, int sp, int digits)
{
	char	*tmp;

	while (--ac > 0)
	{
		digits = 0;
		tmp = av[ac];
		if (!*tmp || ft_onlyspace(tmp))
			return (ERR);
		while (*tmp)
		{
			if (ft_isspace(*tmp))
			{
				sp = 1;
				digits = 0;
				*tmp = ' ';
			}
			else if (ft_isdigit(*tmp) && (!ft_issign(*(tmp + 1))))
				digits++;
			else if (!ft_issign(*tmp) || digits > 10 || ft_isspace(*(tmp + 1)) \
				|| (ft_issign(*tmp) && (!*(tmp + 1) || ft_issign(*(tmp + 1)))))
				return (ERR);
			tmp++;
		}
	}
	return (sp);
}

char	**ft_split_args(int ac, char **av)
{
	char	**sp;
	char	*args;
	int		arg_len;

	arg_len = ft_arg_charcount(ac, av) + (ac - 2);
	args = malloc(arg_len + 1);
	if (!args)
		return (NULL);
	args[arg_len] = 0;
	ft_copie_args(ac, av, args);
	sp = ft_split(args, ' ');
	if (!sp)
		return (free(args), NULL);
	return (free(args), sp);
}

void	ft_copie_args(int ac, char **av, char *args)
{
	char	*args_tmp;
	char	*av_tmp;
	int		idx;

	args_tmp = args;
	idx = 0;
	while (++idx < ac)
	{
		av_tmp = av[idx];
		while (*av_tmp)
			*args_tmp++ = *av_tmp++;
		if (idx != ac - 1)
			*args_tmp++ = ' ';
	}
}

t_node	*ft_arg_to_lst(t_node *stA, t_node *next_node, int idx, char **av)
{
	t_node	*node;
	long	n;

	if (idx < 0 || (!ft_isdigit(*av[idx]) && !ft_issign(*av[idx])))
	{
		stA->next = next_node;
		return (stA);
	}
	node = calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);
	node->next = next_node;
	if (stA == next_node)
		stA->prev = node;
	n = ft_atoi(av[idx]);
	if (INT_MIN <= n && n <= INT_MAX)
		node->n = n;
	else
		return (free(node), NULL);
	node->prev = ft_arg_to_lst(stA, node, --idx, av);
	if (!node->prev)
		return (free(node), NULL);
	return (node);
}
