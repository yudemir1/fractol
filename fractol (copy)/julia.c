/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:42:14 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 21:30:55 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(char *d1, char *d2)
{
	t_fractal	d;

	if (test(d1, d2))
		win_close(&d);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "Fractol");
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.bpp, &d.line_length, &d.endian);
	d.julia_cx = ft_atof(d1);
	d.julia_cy = ft_atof(d2);
	d.zoom = 1.0;
	d.offset_x = 0.0;
	d.offset_y = 0.0;
	d.fractal_type = 1;
	draw_julia(&d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	mlx_key_hook(d.win, key_hook, &d);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_loop(d.mlx);
}

void	draw_julia(t_fractal *d)
{
	t_julia	j;

	j.s = 0.5 * d->zoom;
	j.y = 0;
	while (j.y < HEIGHT)
	{
		j.x = 0;
		while (j.x < WIDTH)
		{
			j.zx = ((j.x - WIDTH / 2.0) / (j.s * WIDTH)) + d->offset_x;
			j.zy = ((j.y - HEIGHT / 2.0) / (j.s * HEIGHT)) + d->offset_y;
			j.iter = 0;
			while (j.zx * j.zx + j.zy * j.zy < 4 && j.iter < MAX_ITER)
			{
				j.temp = j.zx * j.zx - j.zy * j.zy + d->julia_cx;
				j.zy = 2 * j.zx * j.zy + d->julia_cy;
				j.zx = j.temp;
				j.iter++;
			}
			j.color = (j.iter * 255 / MAX_ITER) << 8;
			put_pixel(d, j.x, j.y, j.color);
			j.x++;
		}
		j.y++;
	}
}
