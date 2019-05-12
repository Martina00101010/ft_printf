/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/12 18:41:28 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		ft_printf(char *s, ...)
{
	va_list		ap;
	int			d;
	char		*e;
	char		c;

	va_start(ap, s);
	while (*s)
	{
		if (*s == 's')
		{
			e = va_arg(ap, char *);
			printf("%s\n", e);
		}
		else if (*s == 'd')
		{
			d = va_arg(ap, int);
			printf("%i\n", d);
		}
		else if (*s == 'c')
		{
			c = va_arg(ap, int);
			printf("%i %zu\n", c, sizeof(c));
		}
		s++;
	}
	return (0);
}
