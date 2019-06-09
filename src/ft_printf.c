/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/06/09 17:58:04 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

int		parse_percent(char **s, t_vaio *v, t_flags flg)
{
	char	*tmp;
	int		len;

	len = flg.width > 1 ? flg.width : 1;
	tmp = v->to_print;
	v->to_print = ft_strnew(v->len + len);
	ft_strcat(v->to_print, tmp);
	free(tmp);
	if (flg.flags & 1 << 3)
	{
		v->to_print[v->len] = '%';
		ft_memset(v->to_print + v->len + 1, ' ', len - 1);
	}
	ft_strrcpy(v->to_print + v->len + len - 1, "%", 1,
			flg.flags & 1 << 1 ? '0' : ' ');
	(*s)++;
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
			flags |= 1 << 0;
		if (**s == '0')
			flags |= 1 << 1;
		if (**s == ' ')
			flags |= 1 << 2;
		if (**s == '-')
			flags |= 1 << 3;
 		if (**s == '+')
			flags |= 1 << 4;
//		if (**s == '%')
//			flags |= 1 << 5;
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
		flg.flags |= 1 << 7;
		flg.precision = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
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
	flg = parse_flags(s);
	if (**s == '%')
		return (parse_percent(s, v, flg));
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
*/	if (**s == 's')
		len = parse_string(v, flg);
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
