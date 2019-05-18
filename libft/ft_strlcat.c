/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:53:13 by pberge            #+#    #+#             */
/*   Updated: 2018/12/12 15:42:29 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t dlen;
	size_t slen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	k = 0;
	i = 0;
	if (size < dlen)
		return (slen + size);
	while (dst[i] != '\0')
		i++;
	while (src[k] != '\0' && ((i + k) < (size - 1)))
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (dlen + slen);
}
