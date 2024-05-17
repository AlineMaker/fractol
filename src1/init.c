/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:28:45 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 05:53:17 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *f, int argc, char **argv)
{
	f->mlx = NULL;
	f->img = NULL;
	if (argc <= 1)
		return (errors(f, too_few_args));
	which_fractal(f, argc, argv);
	f->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!f->mlx)
		return (errors(f, mlx_failure));
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		errors (f, mlx_image_failure);
	f->zoom = 1.5;
	f->iters = ITERS;
	f->color_factor = color_factor(f);
	f->color_scheme = black_and_green;
}
