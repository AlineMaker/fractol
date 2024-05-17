/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alialves <alialves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:06:00 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/14 21:09:42 by alialves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_x_value(const t_fractol *f, int x_coord)
{
	double	relative_x;
	double	x_value;

	relative_x = (double)x_coord / f->img->width;
	x_value = relative_x * f->x_spam - f->x_offset;
	return (x_value);
}

static double	ft_y_value(const t_fractol *f, int y_coord)
{
	double	relative_y;
	double	y_value;

	relative_y = (double)y_coord / f->img->width;
	y_value = relative_y * f->y_spam - f->y_offset;
	return (y_value);
}

void	draw_fractal(t_fractol	*f)
{
	double			x;
	double			y;
	double			z;
	uint32_t		i;
	uint32_t		j;

	i = -1;
	while (++i < f->img->width)
	{
		j = -1;
		while (++j < f->img->height)
		{
			x = ft_x_value(f, i);
			y = ft_y_value(f, j);
			z = f->fractal_function(x, y, f) * f->color_factor;
			mlx_put_pixel(f->img, i, j, scheme_selector(z, f->color_scheme));
		}
	}
}
