/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 05:35:35 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

/*
** choosing param type
*/

static int	parse_param(char **s, t_vaio *v, func_ptr p, char *mask)
{
	t_flags	flg;
	int		len;
	int		i;

	(*s)++;
	i = 0;
	len = 0;
	if (**s)
	{
		flg = parse_flags(s);
		while (**s != mask[i])
			i++;
		len = (p[i])(v, &flg);
		(*s)++;
	}
	return (len);
}

void		ft_set_ptrs(func_ptr *p)
{
	(*p)[0] = parse_percent;
	(*p)[1] = parse_char;
	(*p)[2] = parse_string;
	(*p)[3] = parse_pointer;
	(*p)[4] = parse_int;
	(*p)[5] = parse_int;
	(*p)[6] = parse_octal;
	(*p)[7] = parse_unsigned;
	(*p)[8] = parse_lower_hex;
	(*p)[9] = parse_upper_hex;
}

int			ft_printf(char *s, ...)
{
	t_vaio		v;
	func_ptr	p;
	char		*mask;

	v.len = 0;
	mask = "%cspdiouxX";
	ft_bzero(&v, sizeof(t_vaio));
	ft_memory_error(v.to_print = ft_strnew(BUFFLEN));
	va_start(v.ap, s);
	ft_set_ptrs(&p);
	while (*s)
	{
		if (*s == '%')
			v.len += parse_param(&s, &v, p, mask);
		else
			v.len += parse_text(&s, &(v.to_print), v.len);
	}
	va_end(v.ap);
	write(1, v.to_print, v.len);
	return (v.len);
}
