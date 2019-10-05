/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:10:42 by pberge            #+#    #+#             */
/*   Updated: 2019/10/04 17:40:06 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void			i_align_left(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	flg->preci = flg->preci > out.len ? flg->preci - out.len : 0;
	out.num_sp = flg->width - (out.sign || out.sp_flg) - flg->preci - out.len;
	ft_memset(to_print, ' ', out.sp_flg);
	p = out.sp_flg;
	ft_memset(to_print + p, out.sym, out.sign);
	p += out.sign;
	ft_memset(to_print + p, '0', flg->preci);
	if (!out.preci_zero)
		ft_strcat(to_print, out.number);
	p += flg->preci + out.len;
	ft_memset(to_print + p, ' ', out.num_sp);
}

static void			i_align_right(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	if (flg->flags & PRECISION)
		flg->preci = flg->preci > out.len ? flg->preci - out.len : 0;
	else if (flg->flags & ZERO)
		flg->preci = flg->width - (out.sign || out.sp_flg) - out.len;
	out.num_sp = flg->width - out.sign - flg->preci - out.len;
	ft_memset(to_print, ' ', out.num_sp);
	p = out.num_sp;
	ft_memset(to_print + p, out.sym, out.sign);
	p += out.sign;
	ft_memset(to_print + p, '0', flg->preci);
	if (!out.preci_zero)
		ft_strcat(to_print, out.number);
}

long long			get_i_number(va_list ap, char length)
{
	long long	iparam;
	signed char	scp;
	short		sp;
	int			ip;

	if (length == HHMOD)
	{
		scp = va_arg(ap, int);
		iparam = (long long)scp;
	}
	else if (length == HMOD)
	{
		sp = va_arg(ap, int);
		iparam = (long long)sp;
	}
	else if (length == LLMOD || length == LMOD)
		iparam = va_arg(ap, long long);
	else
	{
		ip = va_arg(ap, int);
		iparam = (long long)ip;
	}
	return (iparam);
}

static t_output		i_output_structure(t_flags *flg, long long iparam)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	if (iparam == 0 && flg->flags & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	out.sym = iparam < 0 ? '-' : '+';
	out.sign = (iparam < 0 || flg->flags & PLUS) ? 1 : 0;
	out.sp_flg = (flg->flags & SPACE && !out.sign) ? 1 : 0;
	out.number = ft_itoa_unsigned(iparam);
	out.len = !out.preci_zero ? ft_strlen(out.number) : 0;
	if (flg->width < out.len + (out.sign || out.sp_flg))
		flg->width = out.len + (out.sign || out.sp_flg);
	if (flg->width < flg->preci + (out.sign || out.sp_flg))
		flg->width = flg->preci + (out.sign || out.sp_flg);
	return (out);
}

int					ft_i(t_vaio *v, t_flags *flg)
{
	long long	iparam;
	t_output	out;

	iparam = get_i_number(v->ap, flg->length);
	out = i_output_structure(flg, iparam);
	if (out.number == NULL)
		ft_the_end(v);
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
		i_align_left(flg, out, v->to_print + v->len);
	else
		i_align_right(flg, out, v->to_print + v->len);
	free(out.number);
	return (flg->width);
}
