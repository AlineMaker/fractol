/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:20 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 04:00:55 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(double real_c, double imaginary_c, void *vars)
{
	int			n_interations;
	double		tmp;
	t_fractol	*f;

	f = vars;
	n_interations = 0;
	while (n_interations < f->iters)
	{
		if ((imaginary_c * imaginary_c + real_c * real_c) > 4.0)
			break ;
		tmp = 2 * real_c * imaginary_c + f->y_seed;
		real_c = real_c * real_c - imaginary_c * imaginary_c + f->x_seed;
		imaginary_c = tmp;
		n_interations++;
	}
	return (n_interations);
}
