/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/05/25 18:41:12 by pberge           ###   ########.fr       */
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
	if ((flg.flags = switch_flag(s)))
		(*s)++;
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

#include <stdio.h>

static int	parse_param(char **s, char **to_print, va_list ap, int size)
{
	int		len;
//	int		d;
//	char	c;
	t_flags	flg;

	len = 0;
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
