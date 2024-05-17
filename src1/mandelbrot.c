/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:05:36 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 04:29:19 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(double real_c, double imaginary_c, void *vars)
{
	unsigned int	n_interations;
	double			real;
	double			img;
	double			tmp;
	t_fractol		*f;

	f = vars;
	real = 0;
	img = 0;
	n_interations = 0;
	while (n_interations < f->iters)
	{
		if ((real * real + img * img) > 4.0)
			break ;
		tmp = 2 * real * img + imaginary_c;
		real = real * real - img * img + real_c;
		img = tmp;
		n_interations++;
	}
	return (n_interations);
}
