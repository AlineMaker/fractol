/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:07:51 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 01:48:23 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	bettle(double real_c, double imaginary_c, void *vars)
{
	double			real_temp;
	double			real;
	double			imaginary;
	t_fractol		*f;
	unsigned int	n;

	real = real_c;
	imaginary = imaginary_c;
	n = 0;
	f = (t_fractol *)vars;
	while ((imaginary_c * imaginary_c + real_c * real_c) < 4 && n < f->iters)
	{
		real_temp = real_c * real_c - imaginary_c * imaginary_c + real;
		imaginary_c = -2 * real_c * imaginary_c + imaginary;
		real_c = real_temp;
		n++;
	}
	return (n);
}
