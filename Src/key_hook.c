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

void	iteration_and_color(int keycode, t_data *p)
{
	if (keycode == 69)
		p->f->iteration_m += 1;
	if (keycode == 78)
		p->f->iteration_m -= 1;
	if (keycode == 83)
		apply_color(p, 1);
	if (keycode == 84)
		apply_color(p, 2);
	if (keycode == 85)
		apply_color(p, 3);
	if (keycode == 86)
		apply_color(p, 4);
}

void	direction(int keycode, t_data *p)
{
	if (keycode == 123)
	{
		p->f->x1 += 100 * (1300 / p->f->zoom) / 1300;
		p->f->x2 += 100 * (1300 / p->f->zoom) / 1300;
	}
	if (keycode == 126)
	{
		p->f->y1 += 100 * (1300 / p->f->zoom) / 1300;
		p->f->y2 += 100 * (1300 / p->f->zoom) / 1300;
	}
	if (keycode == 124)
		p->f->x1 -= 100 * ((1300 / p->f->zoom) / 1300);
	if (keycode == 125)
		p->f->y1 -= 100 * ((1300 / p->f->zoom) / 1300);
}

void	change_fract(int keycode, t_data *p, char *str)
{
	str[0] = '-';
	if (keycode == 11)
	{
		str[1] = 'b';
		checker_fract(str, p);
	}
	if (keycode == 35)
	{
		str[1] = 'p';
		checker_fract(str, p);
	}
	if (keycode == 38)
	{
		str[1] = 'j';
		checker_fract(str, p);
	}
	if (keycode == 46)
	{
		str[1] = 'm';
		checker_fract(str, p);
	}
	str[2] = '\0';
}

int		key_hook(int keycode, t_data *p)
{
	if (keycode == 53)
		exit(0);
	iteration_and_color(keycode, p);
	direction(keycode, p);
	change_fract(keycode, p, p->str);
	if (keycode == 34)
		p->activation = 0;
	if (keycode == 40)
		p->activation = 1;
	if ((chose_fract(p)) == -1)
		return (-1);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	affichage(p);
	return (0);
}
