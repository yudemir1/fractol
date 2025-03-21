/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:50:09 by yudemir           #+#    #+#             */
/*   Updated: 2025/03/21 21:28:34 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ITER_MAX 100
# define ERROR_MSG "Use: ./fractol mandelbrot or ./fractol julia [re] [im]"
# define MAX_ITER 80

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		fractal_type;
	double	julia_cx;
	double	julia_cy;
}			t_fractal;

typedef struct s_julia
{
	int		x;
	int		y;
	int		iter;
	double	zx;
	double	zy;
	double	temp;
	int		color;
	double	s;
}			t_julia;

typedef struct s_mandelbrot
{
	int		x;
	int		y;
	int		iter;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	temp;
	int		color;
	double	s;
}			t_mandelbrot;

double		ft_atof(const char *str);
void		draw_julia(t_fractal *d);
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *str, int fd);
int			mouse_hook(int button, int x, int y, t_fractal *data);
int			key_hook(int keycode, t_fractal *data);
void		draw_mandelbrot(t_fractal *d);
void		put_pixel(t_fractal *data, int x, int y, int color);
int			win_close(t_fractal *data);
void		draw_burning_ship(t_fractal *data);
int			test(char *arg1, char *arg2);
void		burningship_init(void);
void		mandelbrot_init(void);
void		julia_init(char *d1, char *d2);

#endif