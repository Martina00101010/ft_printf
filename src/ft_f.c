/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:57:59 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 09:39:48 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void			f_align_left(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	out.num_sp = flg->width - out.len - (out.sign || out.sp_flg);
	out.len -= !out.preci_zero;
	ft_memset(to_print, out.sign ? out.sym : ' ', out.sign || out.sp_flg);
	p = (out.sign || out.sp_flg);
	ft_strncat(to_print + p, out.number, out.len - flg->preci);
	p += out.len - flg->preci;
	ft_memset(to_print + p, '.', !out.preci_zero);
	p += !out.preci_zero;
	ft_strcat(to_print + p, out.number + out.len - flg->preci);
	p += flg->preci;
	ft_memset(to_print + p, ' ', out.num_sp);
}

static void			f_align_right(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	out.num_sp = flg->width - out.len - (out.sign || out.sp_flg);
	out.len -= !out.preci_zero;
	ft_memset(to_print, ' ', flg->flags & ZERO ? 0 : out.num_sp);
	p = flg->flags & ZERO ? 0 : out.num_sp;
	ft_memset(to_print + p, out.sign ? out.sym : ' ', out.sign || out.sp_flg);
	p += (out.sign || out.sp_flg);
	ft_memset(to_print + p, '0', flg->flags & ZERO ? out.num_sp : 0);
	p += flg->flags & ZERO ? out.num_sp : 0;
	ft_strncat(to_print + p, out.number, out.len - flg->preci);
	p += out.len - flg->preci;
	ft_memset(to_print + p, '.', !out.preci_zero);
	p += !out.preci_zero;
	ft_strcat(to_print + p, out.number + out.len - flg->preci);
}

static t_output		f_output_structure(long double ld, t_flags *flg)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	out.sign = (ld < 0 || flg->flags & PLUS) ? 1 : 0;
	out.sym = ld < 0 ? '-' : '+';
	out.sp_flg = (flg->flags & SPACE && !out.sign) ? 1 : 0;
	if (flg->flags & PRECISION && flg->preci == 0 && !(flg->flags & SHARP))
		out.preci_zero = 1;
	flg->preci = flg->flags & PRECISION ? flg->preci : 6;
	out.number = ft_ftoa((ld < 0 ? -ld : ld), flg->preci);
	out.len = ft_strlen(out.number) + !out.preci_zero;
	if (flg->width < out.len + (out.sign || out.sp_flg))
		flg->width = out.len + (out.sign || out.sp_flg);
	return (out);
}

static long double	ft_get_f(t_vaio *v, t_flags *flg)
{
	long double	ld;
	double		d;

	if (flg->length & BIGL)
		ld = va_arg(v->ap, long double);
	else
	{
		d = va_arg(v->ap, double);
		ld = (long double)d;
	}
	return (ld);
}

int					ft_f(t_vaio *v, t_flags *flg)
{
	t_output	out;
	long double	ld;

	ld = ft_get_f(v, flg);
	out = f_output_structure(ld, flg);
	if (out.number == NULL)
		ft_the_end(v);
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
		f_align_left(flg, out, v->to_print + v->len);
	else
		f_align_right(flg, out, v->to_print + v->len);
	free(out.number);
	return (flg->width);
}
