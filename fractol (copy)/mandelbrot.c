/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:17 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 21:38:17 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	assign_values(t_mandelbrot *m)
{
	m->zy = 0; // filler fonksiyon
	m->zx = 0;
	m->iter = 0;
}

void	mandelbrot_init(void)
{
	t_fractal	d;

	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Fractol");
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.bpp, &d.line_length, &d.endian);
	d.zoom = 1.0;
	d.offset_x = 0.0;
	d.offset_y = 0.0;
	d.fractal_type = 0;
	draw_mandelbrot(&d);
	mlx_key_hook(d.win, key_hook, &d);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_loop(d.mlx);
}

void	draw_mandelbrot(t_fractal *d)
{
	t_mandelbrot	t;

	t.s = 0.5 * d->zoom;
	t.y = 0;
	while (t.y < HEIGHT)
	{
		t.x = 0;
		while (t.x < WIDTH)
		{
			t.cx = ((t.x - WIDTH / 2.0) / (t.s * WIDTH)) + d->offset_x;
			t.cy = ((t.y - HEIGHT / 2.0) / (t.s * HEIGHT)) + d->offset_y;
			assign_values(&t);
			while (t.zx * t.zx + t.zy * t.zy < 4 && t.iter < MAX_ITER)
			{
				t.temp = t.zx * t.zx - t.zy * t.zy + t.cx;
				t.zy = 2 * t.zx * t.zy + t.cy;
				t.zx = t.temp;
				t.iter++;
				put_pixel(d, t.x, t.y, t.color);
			}
			t.color = (t.iter * 255 / MAX_ITER) << 16;
			t.x++;
		}
		t.y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
