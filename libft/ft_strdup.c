/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:05:27 by pberge            #+#    #+#             */
/*   Updated: 2018/12/07 22:19:24 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	if ((s = (char *)malloc(len)) == NULL)
		return (NULL);
	while (len--)
	{
		s[i] = s1[i];
		i++;
	}
	return (s);
}
