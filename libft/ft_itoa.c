/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:32:21 by pberge            #+#    #+#             */
/*   Updated: 2019/03/23 15:21:59 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	int_length(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

static void	fill_s(char **s, int *len, int *n)
{
	while ((*len)--)
	{
		(*s)[*len] = *n % 10 + '0';
		*n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		min;

	min = 0;
	len = int_length(n);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		n *= -1;
		min = 1;
	}
	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	s[len] = '\0';
	fill_s(&s, &len, &n);
	if (min)
		s[0] = '-';
	return (s);
}
