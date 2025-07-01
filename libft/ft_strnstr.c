/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:23:39 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/05/08 18:46:07 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;

	if (!*to_find)
		return ((char *)str);
	while (len && *str)
	{
		i = 0;
		while (to_find[i] == str[i] && len - i)
			if (!to_find[i++ + 1])
				return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
