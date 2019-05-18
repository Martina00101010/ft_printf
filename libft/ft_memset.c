/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:10:39 by pberge            #+#    #+#             */
/*   Updated: 2019/01/20 22:25:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symbol;
	unsigned char	*s;

	if (len == 0)
		return (b);
	symbol = (unsigned char)c;
	s = (unsigned char *)b;
	while (len--)
		*s++ = symbol;
	return (b);
}
