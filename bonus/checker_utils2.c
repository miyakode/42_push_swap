/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:25:47 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2024/10/06 00:26:45 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

unsigned int	ft_random_num(int len)
{
	unsigned int	n;

	n = 123456789 + len;
	n ^= n << 13;
	n ^= n >> 17;
	n ^= n << 5;
	n = n % len;
	return (n);
}
