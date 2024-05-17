/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alialves <alialves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:48:06 by alialves          #+#    #+#             */
/*   Updated: 2024/05/15 21:31:19 by alialves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define	FRACTOL_H

# include <unistd.h>
# include <math.h>
#include "MLX42/MLX42.h"
#include "libft.h"

# define WIDTH 800
# define HEIGHT	800
# define ITERS	100

enum					e_error
{
		too_few_args,
		too_many_args,
		invalid_args,
		extra_args,
		too_few_args_julia,
		mlx_failure,
		mlx_image_failure
};

enum					e_color
{
		black_and_green,
		pi_ratio,
		psico,
		psico_dynamic

};

typedef struct	s_fractol_setup
{
		mlx_t						*mlx;
		mlx_image_t					*img;
		int32_t									x_mouse;
		int32_t									y_mouse;
		double						x_spam;
		double						y_spam;
		double						x_offset;
		double						y_offset;
		double						x_seed;
		double						y_seed;
		double						zoom;
		double						iters;
		double						color_factor;
		int									color_scheme;
		unsigned	int		(*fractal_function)(double,double,void *);
}											t_fractol;

uint32_t							color_rgba(int r, int g, int b, int a);
double								color_factor(t_fractol *f);
double								scheme_selector(double nb, int color_scheme);

double								black_and_green_scheme(double nb);
double								pi_scheme(double nb);
double								psico_scheme(double nb);
double								psico_dynamic_scheme(double nb);

void								which_fractal(t_fractol *f, int argc, char**argv);
unsigned int				mandelbrot(double real_c, double imaginary_c, void *vars);
unsigned int				julia(double real_c, double imaginary_c, void *vars);
unsigned int				bettle(double real_c, double imaginary_c, void *vars);
unsigned int 				celtic(double real_c, double imaginary_c, void *vars);

void								close_hook(void *param);
void								key_hook(mlx_key_data_t keydata, void *param);
void								scroll_hook(double xdelta, double ydelta, void *param);
void								mouse_hook(mouse_key_t button, action_t action,
													modifier_key_t mods, void *param);

void								draw_fractal(t_fractol *f);
void								quit(t_fractol *f, int exit_type);
void								errors(t_fractol *f, int exit_type);
void								init(t_fractol *f, int argc, char **argv);
void								zoom_in(t_fractol *f);
void								zoom_out(t_fractol *f);
void								increase_resolution(t_fractol *f);
void								decrease_resolution(t_fractol *f);

#endif
