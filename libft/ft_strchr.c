/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:02:32 by pberge            #+#    #+#             */
/*   Updated: 2018/12/03 18:19:38 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	p;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	p = (char)c;
	str = (char *)s;
	while (i < len)
	{
		if (str[i] == p)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
