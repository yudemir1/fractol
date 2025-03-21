/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:44:02 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 20:41:17 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *d)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	zoom_factor = 1.2;
	mouse_re = ((x - WIDTH / 2.0) / (0.5 * d->zoom * WIDTH)) + d->offset_x;
	mouse_im = ((y - HEIGHT / 2.0) / (0.5 * d->zoom * HEIGHT)) + d->offset_y;
	if (button == 4)
		d->zoom *= zoom_factor;
	else if (button == 5)
		d->zoom /= zoom_factor;
	d->offset_x = mouse_re - ((x - WIDTH / 2.0) / (0.5 * d->zoom * WIDTH));
	d->offset_y = mouse_im - ((y - HEIGHT / 2.0) / (0.5 * d->zoom * HEIGHT));
	if (d->fractal_type == 0)
		draw_mandelbrot(d);
	else if (d->fractal_type == 1)
		draw_julia(d);
	else if (d->fractal_type == 2)
		draw_burning_ship(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_fractal *d)
{
	double	move_factor;

	move_factor = 0.1 / d->zoom;
	if (keycode == 65307)
		win_close(d);
	else if (keycode == 65361)
		d->offset_x -= move_factor;
	else if (keycode == 65363)
		d->offset_x += move_factor;
	else if (keycode == 65362)
		d->offset_y -= move_factor;
	else if (keycode == 65364)
		d->offset_y += move_factor;
	if (d->fractal_type == 0)
		draw_mandelbrot(d);
	else if (d->fractal_type == 1)
		draw_julia(d);
	else if (d->fractal_type == 2)
		draw_burning_ship(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}
