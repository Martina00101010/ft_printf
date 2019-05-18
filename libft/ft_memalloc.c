/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:20:28 by pberge            #+#    #+#             */
/*   Updated: 2019/01/20 22:43:34 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (size >= 9223372036854775807)
		return (NULL);
	if (!(p = malloc(size)))
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
