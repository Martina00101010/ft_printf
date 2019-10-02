/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 22:10:26 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

/*
** taking string from va list ; applying flags to string
*/

int		ft_s(t_vaio *v, t_flags *flg)
{
	t_output	out;
	char		*to_print;

	out.number = va_arg(v->ap, char *);
	out.number = (out.number == NULL) ? "(null)" : out.number;
	out.len = ft_strlen(out.number);
	if ((flg->flags & PRECISION))
		out.len = flg->preci < out.len ? flg->preci : out.len;
	flg->width = flg->width > out.len ? flg->width : out.len;
	out.num_sp = flg->width - out.len;
	ft_refresh_buffer(v, flg->width);
	to_print = v->to_print + v->len;
	if (flg->flags & MINUS)
	{
		ft_strncat(to_print, out.number, out.len);
		ft_memset(to_print + out.len, ' ', out.num_sp);
	}
	else
	{
		ft_memset(to_print, flg->flags & ZERO ? '0' : ' ', out.num_sp);
		ft_strncat(to_print + out.num_sp, out.number, out.len);
	}
	return (flg->width);
}
