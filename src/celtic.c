/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alialves <alialves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:47:50 by alialves          #+#    #+#             */
/*   Updated: 2024/05/17 12:56:53 by alialves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int 	celtic(double real_c,double imaginary_c, void *vars)
{
	t_fractol		*f;
	double			real;
	double			img;
	double			re_temp;
	int						n_interactions;

	f = (t_fractol *)vars;
	real = 0;
	img = 0;
	n_interactions = -1;
	while((real * real + img * img) < 4 && ++n_interactions < f-> iters)
	{
			re_temp = real * real - img* img;
			img = -2 * real * img + imaginary_c;
			if (re_temp < 0)
					re_temp *= -1;
			real = re_temp + real_c;
	}
	return (n_interactions);
 }
