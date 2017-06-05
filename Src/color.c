/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fratolmandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:36:19 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/16 13:36:20 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/libft.h"

void	modify_palette_1(t_data *p)
{
	COULEUR_1.r = 0;
	COULEUR_1.g = 7;
	COULEUR_1.b = 100;
	COULEUR_2.r = 32;
	COULEUR_2.g = 107;
	COULEUR_2.b = 203;
	COULEUR_3.r = 237;
	COULEUR_3.g = 255;
	COULEUR_3.b = 255;
	COULEUR_4.r = 255;
	COULEUR_4.g = 170;
	COULEUR_4.b = 0;
	COULEUR_5.r = 0;
	COULEUR_5.g = 2;
	COULEUR_5.b = 0;
}

void	modify_palette_2(t_data *p)
{
	COULEUR_1.r = 100;
	COULEUR_1.g = 7;
	COULEUR_1.b = 0;
	COULEUR_2.r = 203;
	COULEUR_2.g = 107;
	COULEUR_2.b = 32;
	COULEUR_3.r = 255;
	COULEUR_3.g = 255;
	COULEUR_3.b = 237;
	COULEUR_4.r = 255;
	COULEUR_4.g = 17;
	COULEUR_4.b = 0;
	COULEUR_5.r = 0;
	COULEUR_5.g = 2;
	COULEUR_5.b = 0;
}

void	modify_palette_3(t_data *p)
{
	COULEUR_1.r = 176;
	COULEUR_1.g = 216;
	COULEUR_1.b = 230;
	COULEUR_2.r = 0;
	COULEUR_2.g = 191;
	COULEUR_2.b = 255;
	COULEUR_3.r = 224;
	COULEUR_3.g = 255;
	COULEUR_3.b = 255;
	COULEUR_4.r = 50;
	COULEUR_4.g = 231;
	COULEUR_4.b = 196;
	COULEUR_5.r = 0;
	COULEUR_5.g = 2;
	COULEUR_5.b = 0;
}

void	modify_palette_4(t_data *p)
{
	COULEUR_1.r = 0;
	COULEUR_1.g = 20;
	COULEUR_1.b = 0;
	COULEUR_2.r = 0;
	COULEUR_2.g = 204;
	COULEUR_2.b = 51;
	COULEUR_3.r = 255;
	COULEUR_3.g = 0;
	COULEUR_3.b = 102;
	COULEUR_4.r = 255;
	COULEUR_4.g = 255;
	COULEUR_4.b = 255;
	COULEUR_5.r = 0;
	COULEUR_5.g = 2;
	COULEUR_5.b = 0;
}

void	apply_color(t_data *p, int palette)
{
	if (palette == 1)
		modify_palette_1(p);
	if (palette == 2)
		modify_palette_2(p);
	if (palette == 3)
		modify_palette_3(p);
	if (palette == 4)
		modify_palette_4(p);
}
