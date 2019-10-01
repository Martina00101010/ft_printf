/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 03:40:21 by pberge           ###   ########.fr       */
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
		len = parse_percent(v, &flg);
	else if (**s == 'i' || **s == 'd')
		len = parse_int(v, &flg);
	else if (**s == 's')
		len = parse_string(v, &flg);
	else if (**s == 'o')
		len = parse_octal(v, &flg);
	else if (**s == 'x')
		len = parse_lower_hex(v, &flg);
	else if (**s == 'X')
		len = parse_upper_hex(v, &flg);
	else if (**s == 'u')
		len = parse_unsigned(v, &flg);
	else if (**s == 'c')
		len = parse_char(v, &flg);
	else if (**s == 'p')
		len = parse_pointer(v, &flg);
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
