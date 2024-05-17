/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:58:57 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 01:59:00 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE 10

long long	ft_atoll(const char *nptr)
{
	long long	res;
	char		sign;
	size_t		i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	res = 0;
	while (ft_isdigit(nptr[i]))
	{
		res = res * BASE + ft_todigit(nptr[i]);
		i++;
	}
	return (res * sign);
}
