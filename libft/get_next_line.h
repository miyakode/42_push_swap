/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:58:04 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/04 10:38:56 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
// max fd by my macbook 256, by ubuntu in 42 1024
# define MAX_FD 256
# define ERROR -1
# define SUCCS 1

typedef struct s_lst
{
	char			*buf;
	char			*nl;
	int				len;
	int				eof;
	int				len_sum;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
int		ft_read_fd(int fd, t_lst *lst);
void	ft_create_line(t_lst *lst, char **line);
void	ft_save_rest(t_lst *lst, t_lst *rest[], int fd);
void	*ft_create_newnode(t_lst *node);

void	ft_list_clear(t_lst **lst);
char	*ft_strncat(char *dst, const char *src, size_t n);

#endif
