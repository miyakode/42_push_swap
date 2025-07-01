/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:40:37 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/05/08 23:43:22 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		i;

	cp = malloc(ft_strlen(s) + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (*s)
		cp[i++] = *s++;
	cp[i] = '\0';
	return (cp);
}
