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

void	apply_change_1(t_data *p, double color_gradient)
{
	if (color_gradient >= 0.0 && color_gradient < 0.16)
	{
		p->f->r = COULEUR_1.r + ((COULEUR_2.r - COULEUR_1.r)
			/ 100) * (color_gradient / (0.16 / 100));
		p->f->g = COULEUR_1.g + ((COULEUR_2.g - COULEUR_1.g)
			/ 100) * (color_gradient / (0.16 / 100));
		p->f->b = COULEUR_1.b + ((COULEUR_2.b - COULEUR_1.b)
			/ 100) * (color_gradient / (0.16 / 100));
	}
	else if (color_gradient >= 0.16 && color_gradient < 0.42)
	{
		p->f->r = COULEUR_2.r + ((COULEUR_3.r - COULEUR_2.r)
			/ 100) * ((color_gradient - 0.16) / (0.26 / 100));
		p->f->g = COULEUR_2.g + ((COULEUR_3.g - COULEUR_2.g)
			/ 100) * ((color_gradient - 0.16) / (0.26 / 100));
		p->f->b = COULEUR_2.b + ((COULEUR_3.b - COULEUR_2.b)
			/ 100) * ((color_gradient - 0.16) / (0.26 / 100));
	}
}

void	apply_change_2(t_data *p, double color_gradient)
{
	if (color_gradient >= 0.42 && color_gradient < 0.6425)
	{
		p->f->r = COULEUR_3.r + ((COULEUR_4.r - COULEUR_3.r)
			/ 100) * ((color_gradient - 0.42) / (0.2225 / 100));
		p->f->g = COULEUR_3.g + ((COULEUR_4.g - COULEUR_3.g)
			/ 100) * ((color_gradient - 0.42) / (0.2225 / 100));
		p->f->b = COULEUR_3.b + ((COULEUR_4.b - COULEUR_3.b)
			/ 100) * ((color_gradient - 0.42) / (0.2225 / 100));
	}
	else if (color_gradient >= 0.6425 && color_gradient < 0.8575)
	{
		p->f->r = COULEUR_4.r + ((COULEUR_5.r - COULEUR_4.r)
			/ 100) * ((color_gradient - 0.6425) / (0.215 / 100));
		p->f->g = COULEUR_4.g + ((COULEUR_5.g - COULEUR_4.g)
			/ 100) * ((color_gradient - 0.6425) / (0.215 / 100));
		p->f->b = COULEUR_4.b + ((COULEUR_5.b - COULEUR_4.b)
			/ 100) * ((color_gradient - 0.6425) / (0.215 / 100));
	}
}

void	apply_change_3(t_data *p, double color_gradient)
{
	if (color_gradient >= 0.8575)
	{
		p->f->r = (COULEUR_5.r / 100) *
			((color_gradient - 0.8575) / (0.1425 / 100));
		p->f->g = (COULEUR_5.g / 100)
			* ((color_gradient - 0.8575) / (0.1425 / 100));
		p->f->b = (COULEUR_5.b / 100)
			* ((color_gradient - 0.8575) / (0.1425 / 100));
	}
}

void	change_color(t_data *p)
{
	double color_gradient;

	color_gradient = (p->f->i / (p->f->iteration_m / 100.0)) / 100.0;
	apply_change_1(p, color_gradient);
	apply_change_2(p, color_gradient);
	apply_change_3(p, color_gradient);
}
