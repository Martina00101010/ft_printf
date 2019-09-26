/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:58:54 by pberge            #+#    #+#             */
/*   Updated: 2019/02/01 18:36:40 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	neg;
	long int	num;
	char		*s;

	s = (char *)str;
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
		if (num * 10 / 10 != num)
			return (neg > 0 ? -1 : 0);
	}
	return (num * neg);
}
