/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alialves <alialves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:11:23 by alialves          #+#    #+#             */
/*   Updated: 2024/05/17 16:30:03 by alialves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

double	black_and_green_scheme(double nb)
{
		int		r;
		int 	g;
		int		b;

		nb = 1 - nb;
		r = 255 * nb * nb;
		g = 255 * nb;
		b = 255 * nb * nb * nb;
		return (color_rgba(r, g, b, 255));
}
double	pi_scheme(double nb)
{
		int		r;
		int		g;
		int		b;

		r = 3.14159 * nb * 255;
		g = nb * 255;
		b = (r + g) % 250;
		return (color_rgba(r, g, b, 255));
}
double	psico_dynamic_scheme(double nb)
{
	double time;
	double r;
	double g;
	double b;

	time = mlx_get_time();
	if (time > 10000)
			time = 10000;
		nb = pow(nb + 10, 3) + pow(nb + 2, 2) + nb * time * 0.1;
		r = (cos(nb * 0.1 + time * 0.5) + 1) * 127;
		g = (cos(nb * 0.2 + time * 0.7) + 1) * 127;
		b = (sin(nb * 0.3 + time * 0.9) + cos(nb * 0.2 + time + 0.3) + 2) * 63;
		return (color_rgba((int)r, (int)g, (int)b, 255));
}
double	scheme_selector(double nb, int color_scheme)
{
	if (color_scheme == black_and_green)
		return (black_and_green_scheme(nb));
	if (color_scheme == pi_ratio)
		return (pi_scheme(nb));
	if (color_scheme == psico)
		return (psico_scheme(nb));
	if (color_scheme == psico__dynamic)
		return (psico_dynamic_scheme(nb));
	return (-1);

}
