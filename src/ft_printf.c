/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:19:01 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 07:36:25 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdlib.h>

/*
** choosing param type
*/

static int	ft_flags(char **s, t_vaio *v, t_convert cvt)
{
	t_flags	flg;
	int		i;
	char	*mask;

	(*s)++;
	i = 0;
	mask = "%cspdiouxXf";
	if (!**s)
		return (0);
	flg = parse_flags(s, v->ap);
	while (mask[i] && **s != mask[i])
		i++;
	if (!mask[i])
		return (0);
	i = (cvt[i])(v, &flg);
	(*s)++;
	return (i);
}

void		ft_convert(t_convert *cvt)
{
	(*cvt)[0] = ft_percent;
	(*cvt)[1] = ft_c;
	(*cvt)[2] = ft_s;
	(*cvt)[3] = ft_p;
	(*cvt)[4] = ft_i;
	(*cvt)[5] = ft_i;
	(*cvt)[6] = ft_o;
	(*cvt)[7] = ft_u;
	(*cvt)[8] = ft_x_low;
	(*cvt)[9] = ft_x_up;
	(*cvt)[10] = ft_f;
}

int			ft_printf(char *s, ...)
{
	t_vaio		v;
	t_convert	cvt;

	ft_bzero(&v, sizeof(t_vaio));
	ft_memory_error(v.to_print = ft_strnew(BUFFLEN));
	va_start(v.ap, s);
	ft_convert(&cvt);
	while (*s)
	{
		if (*s == '%')
			v.len += ft_flags(&s, &v, cvt);
		else
			v.len += ft_text(&s, &v);
	}
	va_end(v.ap);
	write(1, v.to_print, v.len);
	v.ret_val += v.len;
	free(v.to_print);
	return (v.ret_val);
}
