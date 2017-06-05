/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:36:19 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/16 17:46:15 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/libft.h"

void	fill_fract_julia(t_data *p)
{
	p->activation = 0;
	p->f->x_tmp = 0.0;
	p->f->y_tmp = 0.0;
	p->f->z = 0.0;
	p->f->w = 0.0;
	p->f->r = 0;
	p->f->g = 0;
	p->f->b = 0;
	p->f->zoom = 500;
	p->f->iteration_m = 50;
	p->f->x1 = -1.4;
	p->f->x2 = 1.2;
	p->f->y1 = -1.3;
	p->f->y2 = 1.3;
	p->f->c_r = 0.285;
	p->f->c_i = 0.01;
	p->f->image_x = (p->f->x2 - p->f->x1) * p->f->zoom;
	p->f->image_y = (p->f->y2 - p->f->y1) * p->f->zoom;
}

void	fill_fract_mandel(t_data *p)
{
	p->activation = 0;
	p->f->x_tmp = 0.0;
	p->f->y_tmp = 0.0;
	p->f->z = 0.0;
	p->f->w = 0.0;
	p->f->r = 0;
	p->f->g = 0;
	p->f->b = 0;
	p->f->zoom = 500;
	p->f->iteration_m = 50;
	p->f->x1 = -2.1;
	p->f->x2 = 0.5;
	p->f->y1 = -1.3;
	p->f->y2 = 1.3;
	p->f->image_x = (p->f->x2 - p->f->x1) * p->f->zoom;
	p->f->image_y = (p->f->y2 - p->f->y1) * p->f->zoom;
}

void	fill_fract_my_fract(t_data *p)
{
	p->activation = 0;
	p->f->x_tmp = 0.0;
	p->f->y_tmp = 0.0;
	p->f->z = 0.0;
	p->f->w = 0.0;
	p->f->r = 0;
	p->f->g = 0;
	p->f->b = 0;
	p->f->zoom = 350;
	p->f->iteration_m = 50;
	p->f->x1 = -1.4;
	p->f->x2 = 2.5;
	p->f->y1 = -1.4;
	p->f->y2 = 2.4;
	p->f->image_x = (p->f->x2 - p->f->x1) * p->f->zoom;
	p->f->image_y = (p->f->y2 - p->f->y1) * p->f->zoom;
}

void	fill_fract_burning(t_data *p)
{
	p->activation = 0;
	p->f->x_tmp = 0.0;
	p->f->y_tmp = 0.0;
	p->f->z = 0.0;
	p->f->w = 0.0;
	p->f->r = 0;
	p->f->g = 0;
	p->f->b = 0;
	p->f->zoom = 350;
	p->f->iteration_m = 50;
	p->f->x1 = -1.8;
	p->f->x2 = 2.0;
	p->f->y1 = -1.915;
	p->f->y2 = 1.8;
	p->f->image_x = (p->f->x2 - p->f->x1) * p->f->zoom;
	p->f->image_y = (p->f->y2 - p->f->y1) * p->f->zoom;
}
