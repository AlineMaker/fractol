/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:03:59 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 06:23:35 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(unsigned long long n, size_t base_size);

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	char	*str;
	size_t	size;
	size_t	base_size;

	base_size = ft_strlen(base);
	size = count_digits(n, base_size);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (size != 0)
	{
		str[size] = base[n % base_size];
		n /= base_size;
		size--;
	}
	str[size] = base[n % base_size];
	return (str);
}

static size_t	count_digits(unsigned long long n, size_t base_size)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		count++;
		n /= base_size;
	}
	return (count);
}
