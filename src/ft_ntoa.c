/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:52:24 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 08:35:44 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	*ft_itoa_unsigned(long long n)
{
	char		*integer;
	int			len;
	long long	tmp;

	len = 1;
	if (n == LLMIN)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
		n *= -1;
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	if (!(integer = (char *)malloc(len + 1)))
		return (NULL);
	integer[len] = '\0';
	while (len--)
	{
		integer[len] = n % 10 + '0';
		n /= 10;
	}
	return (integer);
}

char	*ft_ulltoa(unsigned long long n)
{
	unsigned long long	tmp;
	int					len;
	char				*ullparam;

	len = 0;
	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 8;
	}
	len = (n == 0) ? 1 : len;
	if (!(ullparam = ft_strnew(len + 1)))
		return (NULL);
	while (--len >= 0)
	{
		ullparam[len] = n % 8 + '0';
		n /= 8;
	}
	return (ullparam);
}
