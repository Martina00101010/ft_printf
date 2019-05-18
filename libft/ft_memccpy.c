/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:40:23 by pberge            #+#    #+#             */
/*   Updated: 2018/12/11 22:29:27 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	p;
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	p = (unsigned char)c;
	while (n--)
	{
		d[i] = s[i];
		if (s[i] == p)
			return (&(dst[++i]));
		i++;
	}
	return (NULL);
}
