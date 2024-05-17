/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:59:51 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 01:59:52 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n, size_t base_size);

char	*ft_itoa_base(int n, const char *base)
{
	char	*str;
	size_t	size;
	long	nb;
	size_t	base_size;

	base_size = ft_strlen(base);
	size = count_digits(n, base_size);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	nb = n;
	if (n < 0)
		nb *= -1;
	while (size != 0)
	{
		str[size] = base[nb % base_size];
		nb /= base_size;
		size--;
	}
	if (n < 0)
		str[size] = '-';
	else
		str[size] = base[nb % base_size];
	return (str);
}

static size_t	count_digits(int n, size_t base_size)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= base_size;
	}
	return (count);
}
