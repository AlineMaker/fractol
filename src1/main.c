/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:30:10 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 05:36:57 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_hook(void *param);

int	main(int argc, char **argv)
{
	t_fractol	f;

	init(&f, argc, argv);
	mlx_close_hook(f.mlx, &close_hook, &f);
	mlx_key_hook(f.mlx, &key_hook, &f);
	mlx_mouse_hook(f.mlx, &mouse_hook, &f);
	mlx_scroll_hook(f.mlx, &scroll_hook, &f);
	mlx_loop_hook(f.mlx, ft_hook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}

static void	ft_hook(void *param)
{
	t_fractol	*f;

	f = param;
	draw_fractal(f);
}
