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
#include <unistd.h>

int		ft_printf(char *s, ...)
{
	va_list		ap;
//	char		*e;
	char		*dup;
	int		smb;

	smb = 0;
	dup = s;
	va_start(ap, s);
	while (*s)
	{
		smp++;
		if (*s == '%' && s - dup > 0)
		{
			write(1, dup, s - dup);
			write(1, "\n", 1);
//			e = va_arg(ap, char *);
//			printf("%s\n", e);
		}
		s++;
	}
	return (smp);
}
