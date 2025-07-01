/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:11:25 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/09 17:15:36 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_list_clear(t_lst **lst)
{
	if ((*lst)->next)
		ft_list_clear(&((*lst)->next));
	free((*lst)->buf);
	free(*lst);
	*lst = NULL;
}

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char			*tmp;
	unsigned int	d_len;

	d_len = ft_strlen(dst);
	tmp = dst + d_len;
	while (*src && n-- > 1)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dst);
}
