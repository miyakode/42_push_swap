/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:32:42 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 16:46:41 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

# define A 0
# define B 1
# define ERR -1

typedef enum e_op
{
	NONE,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	DEL
}	t_op;

typedef struct s_node
{
	int				n;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_sortinfo
{
	int	from;
	int	to;
	int	min;
	int	max;
	int	pivot;
	int	pivot2;
	int	len;
}	t_sortinfo;

/*
#ifdef TEST
# include "ps_test.h"
#endif
*/

void			ft_create_stack(t_node **stack, int idx);
void			ft_free_stacks(t_node **stack);

int				ft_create_lst(t_node *stA, int ac, char **av);
int				ft_valid_chars(int ac, char **av, int sp, int digits);
char			**ft_split_args(int ac, char **av);
void			ft_copie_args(int ac, char **av, char *args);
t_node			*ft_arg_to_lst(t_node *stackA, t_node *next_node, int idx, \
char **av);

int				ft_compressor(t_node *stA, int len);
void			ft_quicksort_comp(t_node **adr_lst, int start, int end);
unsigned int	ft_partition(t_node **lst, int start, int end, \
unsigned int p_idx);
void			ft_swap_adr(t_node **lst, int idx1, int idx2);
void			ft_create_adr_lst(t_node *stA, int len, t_node **lst);

int				ft_sort_stack(t_node **stack);
int				ft_double_idx(t_node *stA);
int				ft_2num_sort(t_node **st);
int				ft_3num_sort(t_node **st);
void			ft_6num_sort(t_node **st, int len);

void			ft_over6_sort(t_node **st, t_sortinfo *infos, int lst_end);
void			ft_partition_to_b(t_node **st, t_sortinfo *infos, int pb_count);
void			ft_part_bot(t_node **st, t_sortinfo *infos);
void			ft_part_top(t_node **st, t_sortinfo *infos);
void			ft_back_part(t_node **st, t_sortinfo *infos, int back_to_bot);
void			ft_sort_to_a(t_node **st, int lst_end);

void			ft_op_call(t_node **st, int op);
void			ft_op_double(t_node **st, int op);
void			ft_swap(t_node *st);
void			ft_rotate(t_node *st);
void			ft_reverse(t_node *st);
void			ft_push(t_node *from, t_node *to);

int				ft_lstlen(t_node *stack);
void			ft_free_lst(t_node *stack, t_node *tmp);
void			ft_free_arglst(char **lst, int arg_count);
int				ft_sorted(t_node *st);
int				ft_check_stacklen(t_node *st, int len);
int				ft_onlyspace(char *s);
int				ft_arg_charcount(int ac, char **av);
unsigned int	ft_random_num(int len);
void			ft_setinfos(t_sortinfo *infos, int from, int min, int max);
void			ft_print_op(int op);

#endif
