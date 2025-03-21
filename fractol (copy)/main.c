/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:48:33 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 21:28:50 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractal *d, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * d->line_length + x * (d->bpp / 8));
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = d->addr + offset;
		*(unsigned int *)dst = color;
	}
}

int	win_close(t_fractal *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
}

int	main(int ac, char **av)
{
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || ((ac == 4
				|| ac == 2) && !ft_strncmp(av[1], "julia", 5)) || (ac == 2
			&& !ft_strncmp(av[1], "burningship", 12)))
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10))
			mandelbrot_init();
		else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		{
			julia_init(av[2], av[3]);
		}
		else if (!ft_strncmp(av[1], "julia", 5) && ac == 2)
			julia_init("-0.53781", "0.51293");
		else if (!ft_strncmp(av[1], "burningship", 12))
			burningship_init();
	}
	else
		putstr_fd(ERROR_MSG, 2);
	return (0);
}
