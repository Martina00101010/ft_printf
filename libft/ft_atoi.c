/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:58:54 by pberge            #+#    #+#             */
/*   Updated: 2018/12/07 22:29:45 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	neg;
	unsigned long long	num;
	unsigned char		*s;

	s = (unsigned char *)str;
	num = 0;
	neg = 1;
	while (*s == ' ' || *s == '\f' || *s == '\v'
			|| *s == '\n' || *s == '\r' || *s == '\t')
		s++;
	if (*s == '-')
		neg = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		num *= 10;
		num += (*s - '0');
		s++;
	}
	if (num > 9223372036854775807 && neg == 1)
		return (-1);
	if (num > 9223372036854775807)
		return (0);
	return (num * neg);
}
