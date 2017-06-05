/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:56:33 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/16 17:48:09 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define COULEUR_1 p->palette.color_1
# define COULEUR_2 p->palette.color_2
# define COULEUR_3 p->palette.color_3
# define COULEUR_4 p->palette.color_4
# define COULEUR_5 p->palette.color_5

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_pcolor
{
	t_color		color_1;
	t_color		color_2;
	t_color		color_3;
	t_color		color_4;
	t_color		color_5;
}				t_pcolor;

typedef	struct	s_fractal
{
	double		w;
	double		z;
	double		x_tmp;
	double		y_tmp;
	int			x;
	int			y;
	int			r;
	int			g;
	int			b;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			iteration_m;
	double		zoom;
	double		image_x;
	double		image_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	double		tmp;
	int			verif;
}				t_fractal;

typedef	struct	s_data
{
	char		*str;
	void		*mlx;
	void		*win;
	void		*img;
	char		*picture;
	int			endian;
	int			x;
	int			y;
	char		bobby;
	int			bits;
	int			size_line;
	int			activation;
	t_fractal	*f;
	t_pcolor	palette;
}				t_data;

int				error(int error);
void			affichage(t_data *p);
int				checker_fract(char *billy, t_data *p);
void			affichage(t_data *p);
int				mousehook_julia(int x, int y, t_data *p);
void			change_color(t_data *p);
void			apply_color(t_data *p, int palette);
double			my_abs(double a);
int				chose_fract(t_data *p);
int				key_hook(int keycode, t_data *p);
void			fill_fract_burning(t_data *p);
void			fill_fract_my_fract(t_data *p);
void			fill_fract_mandel(t_data *p);
void			fill_fract_julia(t_data *p);
int				mousehook(int mousecode, int x, int y, t_data *p);
void			algo_julia(t_data *d);
void			algo_my_fract(t_data *d);
void			algo_mandelbrot(t_data *d);
void			algo_burning(t_data *d);
#endif
