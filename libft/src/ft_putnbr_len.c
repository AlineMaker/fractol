/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:01:38 by sueno-te          #+#    #+#             */
/*   Updated: 2024/03/02 06:12:55 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_len(long long number, char *base, int fd)
{
	unsigned long long	absolute_number;
	size_t				base_lenght;
	size_t				printed_chars;

	printed_chars = 0;
	if (number < 0)
	{
		ft_putchar('-');
		printed_chars++;
		absolute_number = -number;
	}
	else
		absolute_number = number;
	base_lenght = ft_strlen(base);
	if (absolute_number >= base_lenght)
		printed_chars += ft_putnbr_len(absolute_number / base_lenght, base, fd);
	ft_putchar_fd(base[absolute_number % base_lenght], fd);
	printed_chars++;
	return (printed_chars);
}
