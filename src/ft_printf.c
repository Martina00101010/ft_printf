/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/09/27 14:36:49 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

/*
** parsing length modifiers
*/

int		parse_length(char **s, t_flags *flg)
{
	int		len;

	len = 0;

	if (**s == 'h' && *(*s + 1) == 'h')
		flg->length |= HHMOD;
	else if (**s == 'h')
		flg->length |= HMOD;
	else if (**s == 'l' && *(*s + 1) == 'l')
		flg->length |= LLMOD;
	else if (**s == 'l')
		flg->length |= LMOD;
	return (len);
}

int		parse_percent(t_vaio *v, t_flags flg)
{
	char	*tmp;
	int		len;

	len = flg.width > 1 ? flg.width : 1;
/* oh my! change this */
	tmp = v->to_print;
	v->to_print = ft_strnew(v->len + len);
	ft_strcat(v->to_print, tmp);
	free(tmp);
/* till there */
	if (flg.flags & MINUS)
	{
		v->to_print[v->len] = '%';
		ft_memset(v->to_print + v->len + 1, ' ', len - 1);
	}
	else
		ft_strrcpy(v->to_print + v->len + len - 1, "%", 1,
			flg.flags & 1 << 1 ? '0' : ' ');
	return (len);
}

/*
** switch on flags from parse-string
*/

char	switch_flag(char **s)
{
	char	flags;

	flags = 0;
	while (**s == '#' || **s == '0' || **s == ' ' ||
			**s == '-' || **s == '+')
	{
		if (**s == '#')
			flags |= SHARP;
		if (**s == '0')
			flags |= ZERO;
		if (**s == ' ')
			flags |= SPACE;
		if (**s == '-')
			flags |= MINUS;
 		if (**s == '+')
			flags |= PLUS;
		(*s)++;
	}
	return (flags);
}

/*
**  skip dollar
**  consider filling flag
**  ft_atoi <- width
**  skip dot
**  ft_atoi <- length
*/

static t_flags	parse_flags(char **s)
{
	char	*ptr;
	t_flags	flg;

	ft_memset((void *)&flg, 0, sizeof(t_flags));
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
		flg.flags |= PRECISION;
		flg.precision = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	parse_length(s, &flg);
	return (flg);
}

/*
** detaching text from string-in-parse ; appending detached to print-string
*/

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

/*
** choosing param type
*/

static int	parse_param(char **s, t_vaio *v)
{
	int		len;
//	int		d;
//	char	c;
	t_flags	flg;

	(*s)++;
	len = 0;
	flg = parse_flags(s);
	if (**s == '%')
		len = parse_percent(v, flg);
	else if (**s == 'i')
		len = parse_int(v, flg);
	else if (**s == 's')
		len = parse_string(v, flg);
/*	printf("param %i\n", flg.param);
	printf("fill  %i\n", flg.fill_flag);
	printf("width %i\n", flg.width);
	printf("preci %i\n", flg.precision);
	printf("#     %i\n", flg.flags & 1);
	printf("0     %i\n", flg.flags & 1 << 1);
	printf("sp    %i\n", flg.flags & 1 << 2);
	printf("-     %i\n", flg.flags & 1 << 3);
	printf("+     %i\n", flg.flags & 1 << 4);
	printf("%%     %i\n", flg.flags & 1 << 5);
*/
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
*/
	(*s)++;
	return (len);
}

int			ft_printf(char *s, ...)
{
	t_vaio	v;

//	ft_bzero(&v, sizeof(t_vaio));
//	ft_memset(&v, sizeof(t_vaio), 0);
	v.len = 0;
	va_start(v.ap, s);
	v.to_print = ft_strnew(BUFFLEN);
	while (*s)
	{
		if (*s == '%')
			v.len += parse_param(&s, &v);
		else
			v.len += parse_text(&s, &(v.to_print), v.len);
	}
	va_end(v.ap);
	write(1, v.to_print, v.len);
//	ft_putnbr(v.len);
	return (v.len);
}
