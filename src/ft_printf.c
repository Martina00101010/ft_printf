/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/26 19:01:24 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

char	switch_flag(char **s)
{
	char	flags;

	flags = 0;
	while (**s == '#' || **s == '0' || **s == ' ' ||
			**s == '-' || **s == '+' || **s == '%')
	{
		if (**s == '#')
			flags |= 1 << 0;
		if (**s == '0')
			flags |= 1 << 1;
		if (**s == ' ')
			flags |= 1 << 2;
		if (**s == '-')
			flags |= 1 << 3;
		if (**s == '+')
			flags |= 1 << 4;
		if (**s == '%')
			flags |= 1 << 5;
		(*s)++;
	}
	return (flags);
}

/*
**  ft_atoi <- param num
**  skip dollar
**  consider filling flag
**  ft_atoi <- width
**  skip dot
**  ft_atoi <- length
*/

static t_flags	parse_flags(char **s)
{
	int		len;
	char	*ptr;
	t_flags	flg;

	ft_memset((void *)&flg, 0, sizeof(t_flags));
	len = 0;
	if ((ptr = ft_strchr(*s, '$')))
	{
		flg.param = ft_atoi(*s);
		*s += ptr - *s + 1;
	}
	flg.flags = switch_flag(s);
	if ((flg.width = ft_atoi(*s)))
		while (**s >= '0' && **s <= '9')
			(*s)++;
	if (**s == '.')
	{
		(*s)++;
		flg.precision = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	return (flg);
}

static int	parse_text(char **s, char **to_print, int vlen)
{
	int		slen;
	char	*tmp;

	slen = 0;
	while ((*s)[slen] != '%' && (*s)[slen] != '\0')
		slen++;
	tmp = *to_print;
	*to_print = ft_strnew(vlen + slen);		// NULL validation
	ft_strcat(*to_print, tmp);
	ft_strncat(*to_print + vlen, *s, slen);
	free(tmp);
	*s += slen;
	return (slen);
}

#include <stdio.h>

static int	parse_param(char **s, t_vaio *v)
{
	int		len;
//	int		d;
//	char	c;
	t_flags	flg;

	(*s)++;
	flg = parse_flags(s);
	printf("param %i\n", flg.param);
	printf("fill  %i\n", flg.fill_flag);
	printf("width %i\n", flg.width);
	printf("preci %i\n", flg.precision);
	printf("#     %i\n", flg.flags & 1);
	printf("0     %i\n", flg.flags & 1 << 1);
	printf("sp    %i\n", flg.flags & 1 << 2);
	printf("-     %i\n", flg.flags & 1 << 3);
	printf("+     %i\n", flg.flags & 1 << 4);
	printf("%%     %i\n", flg.flags & 1 << 5);
	if (**s == 's')
		v->len += parse_string(v, flg);
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
*/	(*s)++;
	return (len);
}

int			ft_printf(char *s, ...)
{
	t_vaio	v;
	char	*to_print;

	va_start(v.ap, s);
	v.len = 0;
	v.to_print = ft_strnew(v.len);
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
