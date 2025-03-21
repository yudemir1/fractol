/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:01:33 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 21:24:42 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(void)
{
	t_fractal	d;

	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Fractol");
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.bpp, &d.line_length, &d.endian);
	d.zoom = 1.0;
	d.offset_x = 0.0;
	d.offset_y = 0.0;
	d.fractal_type = 2;
	draw_burning_ship(&d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_key_hook(d.win, key_hook, &d);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_loop(d.mlx);
}

void	draw_burning_ship(t_fractal *d)
{
	int	color;

	int x, y, iter, max_iter = 100;
	double zx, zy, cx, cy, temp;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cx = ((x - WIDTH / 2.0) / (0.5 * d->zoom * WIDTH)) + d->offset_x;
			cy = ((y - HEIGHT / 2.0) / (0.5 * d->zoom * HEIGHT)) + d->offset_y;
			zx = 0;
			zy = 0;
			iter = 0;
			while (zx * zx + zy * zy < 4 && iter < max_iter)
			{
				temp = zx * zx - zy * zy + cx;
				zy = fabs(2 * zx * zy) + cy;
				zx = fabs(temp);
				iter++;
			}
			color = (iter * 255 / max_iter) << 16;
			put_pixel(d, x, y, color);
			x++;
		}
		y++;
	}
}
