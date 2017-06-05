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

int		checker_fract_2(char *billy, t_data *p)
{
	if (ft_strcmp(billy, "-p") == 0)
	{
		p->bobby = 'p';
		fill_fract_my_fract(p);
		algo_my_fract(p);
	}
	else if (ft_strcmp(billy, "-b") == 0)
	{
		p->bobby = 'b';
		fill_fract_burning(p);
		algo_burning(p);
	}
	if (ft_strcmp(billy, "-j") != 0 && ft_strcmp(billy, "-m") != 0 &&
			ft_strcmp(billy, "-maps") != 0
		&& ft_strcmp(billy, "-b") != 0 && ft_strcmp(billy, "-p") != 0)
		return (-1);
	return (0);
}

int		checker_fract(char *billy, t_data *p)
{
	int error;

	if (ft_strcmp(billy, "-j") == 0)
	{
		p->bobby = 'j';
		fill_fract_julia(p);
		algo_julia(p);
	}
	else if (ft_strcmp(billy, "-m") == 0)
	{
		p->bobby = 'm';
		fill_fract_mandel(p);
		algo_mandelbrot(p);
	}
	else if (ft_strcmp(billy, "-maps") == 0)
	{
		return (1);
	}
	if ((checker_fract_2(billy, p)) == -1)
		error = -1;
	if (error == -1)
		return (-1);
	return (0);
}

int		mlx_fonction(t_data *p)
{
	if (!(p->mlx = mlx_init()))
		return (-1);
	if (!(p->win = mlx_new_window(p->mlx, p->x, p->y, "projet graph 42")))
		return (-1);
	if (!(p->img = mlx_new_image(p->mlx, p->x, p->y)))
		return (-1);
	if (!(p->picture = mlx_get_data_addr(p->img,
		&(p->bits), &(p->size_line), &(p->endian))))
		return (-1);
	return (0);
}

int		main(int argv, char **argc)
{
	t_data		p;
	t_fractal	f;

	p.f = &f;
	if (!(p.str = malloc(sizeof(char) * 3)))
		return (-1);
	if (argv != 2)
		return (error(1));
	apply_color(&p, 1);
	p.x = 1300;
	p.y = 1300;
	if ((mlx_fonction(&p)) != 0)
		return (error(4));
	if (checker_fract(argc[1], &p) == 1)
		return (error(2));
	if (checker_fract(argc[1], &p) == -1)
		return (error(3));
	if (((mlx_key_hook(p.win, key_hook, &p)) == -1) ||
		((mlx_hook(p.win, 6, 1L << 6, &(mousehook_julia), &p)) == -1)
		|| ((mlx_mouse_hook(p.win, mousehook, &p)) == -1))
		return (error(5));
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	affichage(&p);
	mlx_loop(p.mlx);
	return (0);
}
