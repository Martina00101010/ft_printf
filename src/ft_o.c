/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:08:46 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 20:55:56 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void			o_align_right(t_flags *flg, t_output out, char *to_print)
{
	if (flg->flags & PRECISION)
		flg->preci = flg->preci > out.len + out.sp_flg ? \
			flg->preci - out.len : out.sp_flg;
	else if (flg->flags & ZERO)
		flg->preci = flg->width - out.len;
	else
		flg->preci += out.sp_flg;
	out.num_sp = flg->width - flg->preci - out.len;
	ft_memset(to_print, ' ', out.num_sp);
	ft_memset(to_print + out.num_sp, '0', flg->preci);
	if (!out.preci_zero || flg->flags & SHARP)
		ft_strcat(to_print, out.number);
}

static void			o_align_left(t_flags *flg, t_output out, char *to_print)
{
	flg->preci = flg->preci > out.len + out.sp_flg ?
		flg->preci - out.len : out.sp_flg;
	out.num_sp = flg->width - flg->preci - out.len;
	ft_memset(to_print, '0', flg->preci);
	if (!out.preci_zero || flg->flags & SHARP)
		ft_strcat(to_print, out.number);
	ft_memset(to_print + flg->preci + out.len, ' ', out.num_sp);
}

static t_output		o_output_structure(t_flags *flg, unsigned long long oparam)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	if (oparam == 0 && flg->flags & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	out.sp_flg = (flg->flags & SHARP) ? 1 : 0;
	out.number = ft_ulltoa(oparam);
	out.len = out.preci_zero ? 0 : ft_strlen(out.number);
	if (flg->flags & SHARP && oparam == 0)
	{
		out.len = 1;
		out.sp_flg = 0;
	}
	if (flg->width < out.len + out.sp_flg)
		flg->width = out.len + out.sp_flg;
	if (flg->width < flg->preci)
		flg->width = flg->preci;
	return (out);
}

unsigned long long	get_oux_number(va_list ap, char length)
{
	unsigned long long	oparam;
	unsigned char		ucp;
	unsigned short		usp;
	unsigned int		uip;

	if (length == HHMOD)
	{
		ucp = va_arg(ap, int);
		oparam = (unsigned long long)ucp;
	}
	else if (length == HMOD)
	{
		usp = va_arg(ap, int);
		oparam = (unsigned long long)usp;
	}
	else if (length == LLMOD || length == LMOD)
		oparam = va_arg(ap, unsigned long long);
	else
	{
		uip = va_arg(ap, unsigned int);
		oparam = (unsigned long long)uip;
	}
	return (oparam);
}

/*
** convert unsigned int to char * in octal -> oparam
** count length of oparam
** write octal to to_print
** return width of written string -> flg.width
*/

int					ft_o(t_vaio *v, t_flags *flg)
{
	unsigned long long	oparam;
	t_output			out;

	oparam = get_oux_number(v->ap, flg->length);
	out = o_output_structure(flg, oparam);
	if (out.number == NULL)
		ft_the_end(v);
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
		o_align_left(flg, out, v->to_print + v->len);
	else
		o_align_right(flg, out, v->to_print + v->len);
	free(out.number);
	return (flg->width);
}
