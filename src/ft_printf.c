/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/18 17:30:09 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	parse_text(char **s, char **to_print, int size)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '%' && (*s)[len] != '\0')
		len++;
	tmp = *to_print;
//	*to_print = ft_strnew(size + len + 1);
//	*to_print = ft_strjoin();
//	free(tmp);
	*s += len;
	return (len);
}
/*
static int	parse_backlash()
{
	return (1);
}


static int	parse_param(char *s, va_list ap, char **to_print)
{
	int		len;
	int		d;
	char	*e;
	char	c;

	len = 0;
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
	return (len);
}
*/

int			ft_printf(char *s, ...)
{
	va_list	ap;
	size_t	len;
	char	*to_print;
//	char	*tmp;

	va_start(ap, s);
	len = 0;
	to_print = ft_strnew(len);
	while (*s)
	{
//		if (*s == '\')
//			parse_backslash();
//		else if (*s == '%')
			//len += parse_param(s + 1, ap, char **to_print);
//		else
			len += parse_text(&s, &to_print, len);
		s++;
	}
//	write(1, to_print, len);
	printf("%s\n", to_print);
	return (len);
}
