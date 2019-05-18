/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:30:53 by pberge            #+#    #+#             */
/*   Updated: 2019/01/29 16:52:56 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		h;
	int		n;
	char	*hay;

	hay = (char*)haystack;
	n = 0;
	h = 0;
	if (hay[0] == '\0' && needle[0] == '\0')
		return (hay);
	while (hay[h] != '\0')
	{
		while ((hay[h + n] == needle[n]) && needle[n] != '\0')
			n++;
		if (needle[n] == '\0')
			return (&hay[h]);
		n = 0;
		h++;
	}
	return (NULL);
}
