/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 04:21:02 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 04:39:46 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	celtic(double real_c, double imaginary_c, void *vars)
{
	t_fractol	*f;
	double		real;
	double		img;
	double		re_temp;
	int			n_interactions;

	f = (t_fractol *)vars;
	real = 0;
	img = 0;
	n_interactions = -1;
	while ((real * real + img * img) < 4 && ++n_interactions < f->iters)
	{
		re_temp = real * real - img * img;
		img = -2 * real * img + imaginary_c;
		if (re_temp < 0)
			re_temp *= -1;
		real = re_temp + real_c;
	}
	return (n_interactions);
}
