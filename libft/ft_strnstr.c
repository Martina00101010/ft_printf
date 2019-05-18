/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:05:12 by pberge            #+#    #+#             */
/*   Updated: 2018/12/14 17:39:24 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;

	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	h = 0;
	while (h < len && haystack[h])
	{
		n = 0;
		while ((haystack[h + n] == needle[n]) && ((h + n) < len) && needle[n])
			n++;
		if (needle[n] == '\0')
			return (char *)(haystack + h);
		h++;
	}
	return (NULL);
}
