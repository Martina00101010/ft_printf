/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:37:17 by pberge            #+#    #+#             */
/*   Updated: 2018/12/03 20:40:17 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = (size_t)ft_strlen(src);
	if (dst >= src && dst <= src + len)
		dst = (char *)malloc(len + 1);
	while (i < src_len && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (src_len < len)
		dst[src_len++] = '\0';
	return (dst);
}
