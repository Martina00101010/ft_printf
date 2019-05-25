/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/25 16:02:13 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

static int	parse_text(char **s, char **to_print, int size)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '%' && (*s)[len] != '\0')
		len++;
	tmp = *to_print;
	*to_print = ft_strnew(size + len);		// NULL validation
	ft_strcat(*to_print, tmp);
	ft_strncat(*to_print + size, *s, len);
	free(tmp);
	*s += len;
	return (len);
}

/*
static int	parse_backlash()
{
	return (1);
}
*/

static int	parse_param(char **s, char **to_print, va_list ap, int size)
{
	int		len;
//	int		d;
//	char	c;

	len = 0;
	(*s)++;

	if (**s == 's')
	{
		len += parse_string(ap, to_print, size);
		*s += 1;
	}
/*	else if (*s == 'd')
	{
		d = va_arg(ap, int);
//		printf("%i\n", d);
	}
	else if (*s == 'c')
	{
		c = va_arg(ap, int);
//		printf("%i %zu\n", c, sizeof(c));
	}
*/	return (len);
}

int			ft_printf(char *s, ...)
{
	va_list	ap;
	int		len;
	char	*to_print;

	va_start(ap, s);
	len = 0;
	to_print = ft_strnew(len);
	while (*s)
	{
//		if (*s == '\')
//			parse_backslash();
		if (*s == '%')
			len += parse_param(&s, &to_print, ap, len);
		else
			len += parse_text(&s, &to_print, len);
	}
	va_end(ap);
	write(1, to_print, len);
	return (len);
}
