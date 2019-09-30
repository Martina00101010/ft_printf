/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:55:22 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 00:13:07 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		align_right(t_flags *flg, t_output out, char *to_print)
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

static void		align_left(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	p = out.sp_flg;
	if (out.sp_flg)
		ft_strcat(to_print, flg->flags & CAPITAL_HEX ? "0X": "0x");
	out.num_sp = flg->width - out.sp_flg - flg->preci - out.len;
	ft_memset(to_print + p, '0', flg->preci);
	p += flg->preci;
	ft_strcat(to_print + p, out.number);
	p += out.len;
	ft_memset(to_print + p, ' ', out.num_sp);
}

static char		*ft_xtoa(unsigned long long xparam, char capital)
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
	ft_memory_error((hex = ft_strnew(len + 1)));
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

static t_output	output_structure(t_flags *flg, unsigned long long xparam)
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

static int		parse_hex(t_vaio *v, t_flags flg)
{
	unsigned long long	hex;
	t_output	out;

	hex = get_oux_number(v->ap, flg.length);
	out	= output_structure(&flg, hex);
	if (flg.flags & MINUS)
		align_left(&flg, out, v->to_print + v->len);
	else
		align_right(&flg, out, v->to_print + v->len);
	return (flg.width);
}

int				parse_upper_hex(t_vaio *v, t_flags flg)
{
	flg.flags |= CAPITAL_HEX;
	return (parse_hex(v, flg));
}

int				parse_lower_hex(t_vaio *v, t_flags flg)
{
	return (parse_hex(v, flg));
}
