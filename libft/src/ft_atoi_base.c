/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:58:47 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 01:58:48 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *nptr, const char *base)
{
	int		res;
	char	sign;
	size_t	i;
	size_t	base_size;

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
	base_size = ft_strlen(base);
	while (nptr[i] != '\0' && ft_strchr(base, nptr[i]))
	{
		res = res * base_size + (ft_strchr(base, nptr[i]) - base);
		i++;
	}
	return (res * sign);
}
