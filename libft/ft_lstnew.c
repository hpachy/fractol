/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:32:24 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/10 11:32:25 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*george;

	if (!(george = malloc(sizeof(*george))))
		return (NULL);
	if (content != NULL)
	{
		if (!(george->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(george->content, (void *)content, content_size);
		george->content_size = content_size;
	}
	if (!(content))
	{
		george->content = NULL;
		george->content_size = 0;
	}
	george->next = NULL;
	return (george);
}
