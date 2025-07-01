/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:20:03 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/03 16:00:18 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while (*str == 32 || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (48 <= *str && *str <= 57)
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	return (n * sign);
}
