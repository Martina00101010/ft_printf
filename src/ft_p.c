/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 02:41:39 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 20:30:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static t_output	p_output_structure(t_flags *flg, unsigned long long xparam)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	if (xparam == 0 && flg->flags & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	out.sp_flg = (flg->flags & SHARP) ? 2 : 0;
	out.number = ft_xtoa(xparam, 0);
	out.len = out.preci_zero ? 0 : ft_strlen(out.number);
	flg->preci = (flg->preci > out.len) ? flg->preci - out.len : 0;
	if (flg->width < out.len + out.sp_flg + flg->preci)
		flg->width = out.len + out.sp_flg + flg->preci;
	return (out);
}

int				ft_p(t_vaio *v, t_flags *flg)
{
	unsigned long long	pointer;
	t_output			out;

	flg->flags |= SHARP;
	flg->length |= LLMOD;
	pointer = get_oux_number(v->ap, flg->length);
	out = p_output_structure(flg, pointer);
	if (out.number == NULL)
		ft_the_end(v);
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
		x_align_left(flg, out, v->to_print + v->len);
	else
		x_align_right(flg, out, v->to_print + v->len);
	free(out.number);
	return (flg->width);
}
