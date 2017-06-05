/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:46:25 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 15:46:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;

	if (s == NULL)
		return (NULL);
	s = ft_isspace((char *)s);
	end = ft_strlen(s);
	while (s[end] == '\0' || s[end] == '\n' || s[end] == '\t' || s[end] == ' ')
		end--;
	if (end < 0)
		return (ft_strnew(1));
	s = ft_strsub((char *)s, 0, end + 1);
	return ((char *)s);
}
