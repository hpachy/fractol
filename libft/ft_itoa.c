/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:18:56 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/08 19:13:58 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	long	int stock;
	int			count;
	char		*tab;

	tab = malloc(sizeof(char) * (ft_calcul(n) + 1));
	if (tab == NULL)
		return (NULL);
	stock = n;
	count = ft_calcul(n) - 1;
	if (stock <= 0)
	{
		stock = stock * -1;
		tab[0] = '-';
	}
	while (stock >= 10)
	{
		tab[count] = ((stock % 10) + 48);
		stock = stock / 10;
		count--;
	}
	if (stock < 10)
		tab[count] = (stock + 48);
	tab[ft_calcul(n)] = '\0';
	return (tab);
}
