/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:07:32 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 17:30:40 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <limits.h>

# define A 0
# define B 1
# define ERR -1
# define KO -2

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

/*
# ifdef TEST_BONUS
# include "ps_test.h"
# endif
*/

int				ft_create_stack(t_node **stack);
void			ft_free_stacks(t_node **stack);
void			ft_free_stacks(t_node **stack);
void			ft_free_lst(t_node *stack, t_node *tmp);

int				ft_create_lst(t_node *stA, int ac, char **av);
int				ft_valid_chars(int ac, char **av, int sp, int digits);
char			**ft_split_args(int ac, char **av);
void			ft_copie_args(int ac, char **av, char *args);
t_node			*ft_arg_to_lst(t_node *stA, t_node *next_node, int idx, \
char **av);

int				ft_compressor(t_node *stA, int len);
void			ft_quicksort_comp(t_node **adr_lst, int start, int end);
unsigned int	ft_partition(t_node **lst, int start, int end, \
unsigned int p_idx);
void			ft_swap_adr(t_node **lst, int idx1, int idx2);
void			ft_create_adr_lst(t_node *stA, int len, t_node **lst);

int				ft_get_input(t_node **st, int first);
int				ft_check_line(char *line);
int				ft_op_call(t_node **st, int op);
int				ft_op_double(t_node **st, int op);

int				ft_swap(t_node *st);
int				ft_rotate(t_node *st);
int				ft_reverse(t_node *st);
int				ft_push(t_node *from, t_node *to);

int				ft_arg_charcount(int ac, char **av);
int				ft_issorted(t_node *st);
int				ft_onlyspace(char *s);
int				ft_lstlen(t_node *stack);
void			ft_free_arglst(char **lst, int idx);

unsigned int	ft_random_num(int len);

#endif
