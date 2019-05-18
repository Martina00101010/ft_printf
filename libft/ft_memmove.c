/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:33:44 by pberge            #+#    #+#             */
/*   Updated: 2019/01/20 22:01:58 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (dst);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while ((int)(--len) >= 0)
			ft_memcpy(dst + len, src + len, 1);
	}
	return (dst);
}
