/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:13:38 by pberge            #+#    #+#             */
/*   Updated: 2018/12/07 22:20:10 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_strnew(sizeof(char) * ft_strlen(s));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s);
	while (str[i] != '\0')
	{
		if (f(str[i]))
			str[i] = f(str[i]);
		i++;
	}
	return (str);
}
