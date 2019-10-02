/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:55:22 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 20:48:23 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void			x_align_right(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	if (flg->flags & ZERO && !(flg->flags & PRECISION))
		flg->preci = flg->width - out.sp_flg - out.len;
	out.num_sp = flg->width - out.sp_flg - flg->preci - out.len;
	ft_memset(to_print, ' ', out.num_sp);
	p = out.num_sp;
	if (out.sp_flg)
		ft_strcat(to_print + p, flg->flags & CAPITAL_HEX ? "0X" : "0x");
	p += out.sp_flg;
	ft_memset(to_print + p, '0', flg->preci);
	p += flg->preci;
	if (!out.preci_zero)
		ft_strcat(to_print + p, out.number);
}

void			x_align_left(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	p = out.sp_flg;
	if (out.sp_flg)
		ft_strcat(to_print, flg->flags & CAPITAL_HEX ? "0X" : "0x");
	out.num_sp = flg->width - out.sp_flg - flg->preci - out.len;
	ft_memset(to_print + p, '0', flg->preci);
	p += flg->preci;
	ft_strcat(to_print + p, out.number);
	p += out.len;
	ft_memset(to_print + p, ' ', out.num_sp);
}

char			*ft_xtoa(unsigned long long xparam, char capital)
{
	unsigned long long	tmp;
	char				*hex;
	int					len;

	len = 0;
	capital = (capital) ? 'A' : 'a';
	tmp = xparam;
	while (tmp > 0)
	{
		len++;
		tmp /= 16;
	}
	len = (xparam == 0x0) ? 1 : len;
	if (!(hex = ft_strnew(len + 1)))
		return (NULL);
	while (--len > -1)
	{
		tmp = xparam % 16;
		if (tmp <= 9)
			hex[len] = tmp + '0';
		else
			hex[len] = capital + tmp - 10;
		xparam /= 16;
	}
	return (hex);
}

static t_output	x_output_structure(t_flags *flg, unsigned long long xparam)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	if (xparam == 0 && flg->flags & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	out.sp_flg = (flg->flags & SHARP && xparam != 0) ? 2 : 0;
	out.number = ft_xtoa(xparam, flg->flags & CAPITAL_HEX);
	out.len = out.preci_zero ? 0 : ft_strlen(out.number);
	flg->preci = (flg->preci > out.len) ? flg->preci - out.len : 0;
	if (flg->width < out.len + out.sp_flg + flg->preci)
		flg->width = out.len + out.sp_flg + flg->preci;
	return (out);
}

int				ft_x(t_vaio *v, t_flags *flg)
{
	unsigned long long	hex;
	t_output			out;

	hex = get_oux_number(v->ap, flg->length);
	out = x_output_structure(flg, hex);
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
