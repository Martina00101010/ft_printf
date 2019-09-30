/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/09/30 18:12:15 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

/*
** choosing param type
*/

static int	parse_param(char **s, t_vaio *v)
{
	int		len;
	t_flags	flg;

	(*s)++;
	len = 0;
	flg = parse_flags(s);
	if (**s == '%')
		len = parse_percent(v, flg);
	else if (**s == 'i' || **s == 'd')
		len = parse_int(v, flg);
	else if (**s == 's')
		len = parse_string(v, flg);
	else if (**s == 'o')
		len = parse_octal(v, flg);
/*	printf("param %i\n", flg.param);
	printf("width %i\n", flg.width);
	printf("preci %i\n", flg.preci);
	printf("#     %i\n", flg.flags & 1);
	printf("0     %i\n", flg.flags & 1 << 1);
	printf("sp    %i\n", flg.flags & 1 << 2);
	printf("-     %i\n", flg.flags & 1 << 3);
	printf("+     %i\n", flg.flags & 1 << 4);
	printf("%%     %i\n", flg.flags & 1 << 5);
	printf("hh    %i\n", flg.length & 1);
	printf("h     %i\n", flg.length & 1 << 1);
	printf("ll    %i\n", flg.length & 1 << 2);
	printf("l     %i\n", flg.length & 1 << 3);*/
	(*s)++;
	return (len);
}

int			ft_printf(char *s, ...)
{
	t_vaio	v;

	v.len = 0;
	ft_bzero(&v, sizeof(t_vaio));
	v.to_print = ft_strnew(BUFFLEN);
	va_start(v.ap, s);
	while (*s)
	{
		if (*s == '%')
			v.len += parse_param(&s, &v);
		else
			v.len += parse_text(&s, &(v.to_print), v.len);
	}
	va_end(v.ap);
	write(1, v.to_print, v.len);
	return (v.len);
}
