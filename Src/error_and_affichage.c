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

double	my_abs(double a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

void	affichage(t_data *p)
{
	char	*str;

	str = ft_itoa(p->f->iteration_m);
	mlx_string_put(p->mlx, p->win, 0, 0, 0xFFFFFF, "\n\nITERATION : ");
	mlx_string_put(p->mlx, p->win, 140, 0, 0x00FF00, str);
	free(str);
}

int		error_bis(int error)
{
	if (error == 3)
	{
		write(1, "\n(>_<) AIE!!! ", 14);
		write(1, "==> your map is false <==\n\n", 27);
	}
	if (error == 4)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> MLX FAILED!!!! <==\n\n", 22);
	}
	if (error == 5)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> MLX_HOOK FAILED!!!! <==\n\n", 29);
	}
	return (1);
}

int		error(int error)
{
	if (error == 1)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> wrong numbers of arguments <==\n\n", 36);
		write(1, "==> first: your executable ;", 28);
		write(1, " second : '-' and after that your map ;\n", 40);
		write(1, "\nTo see maps typing your exect and '-maps'\n\n", 43);
	}
	if (error == 2)
	{
		write(1, "\n================================================\n", 50);
		write(1, "\n-j it's a fractal julia", 24);
		write(1, "\n-m it's a fractal mandelbrot", 29);
		write(1, "\n-p it's a fractal who's found by me ^_^", 40);
		write(1, "\n-b it's a fractal burning ship\n", 32);
		write(1, "\n================================================\n", 50);
	}
	error_bis(error);
	return (1);
}
