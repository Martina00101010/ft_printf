/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:08:46 by pberge            #+#    #+#             */
/*   Updated: 2019/09/30 18:01:40 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		align_right(t_flags *flg, t_output out, char *to_print)
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

static void		align_left(t_flags *flg, t_output out, char *to_print)
{
	flg->preci = flg->preci > out.len + out.sp_flg ?
		flg->preci - out.len : out.sp_flg;
	out.num_sp = flg->width - flg->preci - out.len;
	ft_memset(to_print, '0', flg->preci);
	if (!out.preci_zero || flg->flags & SHARP)
		ft_strcat(to_print, out.number);
	ft_memset(to_print + flg->preci + out.len, ' ', out.num_sp);
}

char		*ft_ulltoa(unsigned long long n)
{
	unsigned long long	tmp;
	int					len;
	char				*ullparam;

	len = 0;
	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 8;
	}
	len = (n == 0) ? 1 : len;
	ft_memory_error(ullparam = ft_strnew(len + 1));
	while (--len >= 0)
	{
		ullparam[len] = n % 8 + '0';
		n /= 8;
	}
	return (ullparam);
}

static t_output		output_structure(t_flags *flg, unsigned long long oparam)
{
	t_output	out;

	ft_memset(&out, 0, sizeof(t_output));
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

static unsigned long long		get_number(va_list ap, char length)
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

int		parse_octal(t_vaio *v, t_flags flg)
{
	unsigned long long	oparam;
	t_output			out;

	oparam = get_number(v->ap, flg.length);
	out = output_structure(&flg, oparam);
	if (flg.flags & MINUS)
		align_left(&flg, out, v->to_print + v->len);
	else
		align_right(&flg, out, v->to_print + v->len);
	return (flg.width);
}
