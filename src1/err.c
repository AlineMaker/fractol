/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <rflseijiueno@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:05:51 by sueno-te          #+#    #+#             */
/*   Updated: 2024/05/13 05:01:40 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errors(t_fractol *f, int error)
{
	if (error == too_few_args)
		ft_putstr_fd("ERROR - Missing arguments -> Use: "
			"./fractol < mandelbrot | julia | bettle | celtic >\n", 1);
	else if (error == extra_args)
		ft_putstr_fd("ERROR - This set do not require extra arguments\n", 1);
	else if (error == too_few_args_julia)
		ft_putstr_fd("ERROR - Missing arguments -> Use: "
			"./fractol julia <real_seed> <imaginary_seed>\n"
			"example sets: <0.285> + <0.01> and <-0.8> + <0.156>\n", 1);
	else if (error == mlx_failure)
		ft_putstr_fd("Fail to create MLX instance\n", 1);
	else if (error == mlx_image_failure)
		ft_putstr_fd("Fail to create and place the image.\n,", 1);
	else if (error == invalid_args)
		ft_putstr_fd("Invalid argument.\n"
			"Arguments: mandelbrot | julia | bettle | celtic\n", 1);
	quit (f, EXIT_FAILURE);
}
