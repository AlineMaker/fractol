/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:53:49 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 00:53:53 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *nptr)
{
	int		sign;
	double	nb;
	int		divider;

	sign = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' && ft_isdigit(*(nptr + 1)))
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(*nptr))
		nb = nb * 10 + (*(nptr++) - '0');
	if (*nptr == '.')
		nptr++;
	divider = 10;
	while (ft_isdigit(*nptr))
	{
		nb += (double)(*(nptr++) - '0') / divider;
		divider *= 10;
	}
	return (sign * nb);
}
