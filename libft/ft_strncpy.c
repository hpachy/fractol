/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:39:20 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/04 10:39:22 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int c;

	c = 0;
	while (src[c] != '\0' && (c < len))
	{
		dst[c] = src[c];
		c++;
	}
	while (c < len)
	{
		dst[c] = '\0';
		c++;
	}
	return (dst);
}
