/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frataljulia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:36:19 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/16 13:36:20 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/libft.h"

static void	light_on(t_fractal *f, t_data *p)
{
	if ((f->x >= 0 && f->x < p->x) && (f->y >= 0 && f->y < p->y))
	{
		(p->picture)[(f->x * 4) + (f->y * p->size_line)] = f->b;
		(p->picture)[(f->x * 4) + (f->y * p->size_line) + 1] = f->g;
		(p->picture)[(f->x * 4) + (f->y * p->size_line) + 2] = f->r;
		(p->picture)[(f->x * 4) + (f->y * p->size_line) + 3] = 0;
	}
}

void		init_fractol_burning(t_data *d)
{
	d->f->c_r = ((double)d->f->x - (650) - (d->f->x_tmp / ((1300
		/ (d->f->zoom / 1.1)) / 1300))) / (d->f->zoom) + d->f->x1;
	d->f->c_i = ((double)d->f->y - (650) - (d->f->y_tmp / ((1300
		/ (d->f->zoom / 1.1)) / 1300))) / (d->f->zoom) + d->f->y1;
	d->f->c_r += (1.3) + d->f->x_tmp;
	d->f->c_i += (1.3) + d->f->y_tmp;
	d->f->z_r = 0.0;
	d->f->z_i = 0.0;
	d->f->i = 0;
	d->f->verif = 0;
}

void		algo_burning(t_data *d)
{
	d->f->x = -1;
	d->f->y = -1;
	d->f->x_tmp = d->f->w;
	d->f->y_tmp = d->f->z;
	while (++d->f->y < d->f->image_y)
	{
		while (++d->f->x < d->f->image_x)
		{
			init_fractol_burning(d);
			while ((d->f->verif < 4) && d->f->i < d->f->iteration_m)
			{
				d->f->tmp = d->f->z_r;
				d->f->z_r = my_abs((d->f->z_r * d->f->z_r -
				d->f->z_i * d->f->z_i) + d->f->c_r);
				d->f->z_i = my_abs(2 * d->f->z_i * d->f->tmp + d->f->c_i);
				d->f->i++;
				d->f->verif = d->f->z_r * d->f->z_r + d->f->z_i * d->f->z_i;
			}
			change_color(d);
			light_on(d->f, d);
		}
		d->f->x = -1;
	}
}
