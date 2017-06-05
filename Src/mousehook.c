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

int		chose_fract(t_data *p)
{
	if (p->bobby == 'j')
		algo_julia(p);
	else if (p->bobby == 'm')
		algo_mandelbrot(p);
	else if (p->bobby == 'p')
		algo_my_fract(p);
	else if (p->bobby == 'b')
		algo_burning(p);
	else
		return (-1);
	return (0);
}

int		mousehook_julia(int x, int y, t_data *p)
{
	if (p->activation == 1)
	{
		p->f->c_r = x * ((1300 / p->f->zoom) / 1300) - 1.4;
		p->f->c_i = y * ((1300 / p->f->zoom) / 1300) - 1.3;
		if ((chose_fract(p)) == -1)
			return (-1);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
		affichage(p);
	}
	return (0);
}

void	zoom_up(double *tmp, int x, int y, t_data *p)
{
	(*tmp) = (1300 / p->f->zoom) / 1300;
	p->f->zoom = p->f->zoom * 1.1;
	if (p->f->x_tmp == 0)
	{
		p->f->x_tmp = (x - 650) * (*tmp);
		p->f->y_tmp = (y - 650) * (*tmp);
	}
	else
	{
		p->f->x_tmp += (x - 650) * (*tmp);
		p->f->y_tmp += (y - 650) * (*tmp);
	}
	p->f->iteration_m += 1;
	p->f->w = p->f->x_tmp;
	p->f->z = p->f->y_tmp;
}

int		mousehook(int mousecode, int x, int y, t_data *p)
{
	double		tmp;

	ft_bzero(p->picture, 1300 * 1300 * 4);
	if (mousecode == 1)
		zoom_up(&tmp, x, y, p);
	if (mousecode == 2)
	{
		p->f->zoom /= 1.1;
		tmp = ((1300 / p->f->zoom) / 1300);
		p->f->x_tmp -= (x - 650) * tmp;
		p->f->y_tmp -= (y - 650) * tmp;
		p->f->iteration_m -= 1;
		if (p->f->iteration_m == 0)
			p->f->iteration_m = 1;
		p->f->w = p->f->x_tmp;
		p->f->z = p->f->y_tmp;
	}
	if ((chose_fract(p)) == -1)
		return (-1);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	affichage(p);
	return (0);
}
