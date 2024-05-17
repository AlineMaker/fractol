/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:59:06 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 01:59:08 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull_base(const char *nptr, const char *base)
{
	unsigned long long	res;
	size_t				i;
	size_t				base_size;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	res = 0;
	base_size = ft_strlen(base);
	while (nptr[i] != '\0' && ft_strchr(base, nptr[i]))
	{
		res = res * base_size + (ft_strchr(base, nptr[i]) - base);
		i++;
	}
	return (res);
}
