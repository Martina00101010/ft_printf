/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:57:59 by pberge            #+#    #+#             */
/*   Updated: 2019/10/03 23:50:35 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	ft_ilen(long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

#include <stdio.h>
#include <math.h>

static long long	ft_fract(long double tmp, int preci)
{
	long long	fract;
	int		i;

//	printf("rrrrr%Lfrrrrrrrrr", tmp * pow(10, preci));
	i = -1;
	fract = 0;
	while (++i < preci + 1)
	{
	//	printf("%Lf\t%lli\n", tmp, fract);
		tmp *= 10L;
		fract *= 10L;
		printf("%Lf\t%lli\n", tmp, fract);
		fract += (long long)tmp;
		tmp -= (long long)tmp;
	}
//	printf("tmp: %Lf\tpreci %i", tmp, preci);
	return (fract);
}

static char	*ft_ftoa_unsigned(long long fract, int preci)
{
	char		*f;
	int			len;

	printf("lln: %lli\n", fract);
	if (fract == -9223372036854775808U)
		return (ft_strdup("9223372036854775808"));
	if (!(f = ft_strnew(preci + 1)))
		return (NULL);
	f[preci + 1] = '\0';
	len = ft_ilen(fract);
	while (len--)
	{
		f[len] = fract % 10 + '0';
		fract /= 10;
	}
	return (f);
}

static char	*ft_ftoa(long double fparam, int preci)
{
	long long	intgr;
	long long	fract;
	char	*f;
	char	*in;
	char	*fr;

	int		dot = 1;

	intgr = (long long)fparam;
	fract = ft_fract(fparam - (long double)intgr, preci);
//	printf("one %Lf\ntwo %Lf\n", fparam, fparam - (long double)intgr);
	if (!(f = ft_strnew(ft_ilen(intgr) + ft_ilen(fract) + dot)))
		return (NULL);
	in = ft_itoa_unsigned(intgr);
	fr = ft_ftoa_unsigned(fract, preci);
	printf("fr %s\n", fr);
	ft_strcat(f, in);
	ft_memset(f + ft_strlen(in), '.', dot);
	ft_strcat(f + ft_strlen(in) + dot, fr);
	return (f);
}

static void			f_align_left(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	out.num_sp = flg->width - out.len - (out.sign || out.sp_flg);
	ft_memset(to_print, out.sign ? out.sym : ' ', out.sign || out.sp_flg);
	p = out.sign || out.sp_flg;
	ft_strcat(to_print + p, out.number);
	p += out.len;
	ft_memset(to_print + p, ' ', out.num_sp);
}

static void			f_align_right(t_flags *flg, t_output out, char *to_print)
{
	int		p;

	out.num_sp = flg->width - out.len - (out.sign || out.sp_flg);
	ft_memset(to_print, out.sign ? out.sym : ' ', out.sign || out.sp_flg);
	p = out.sign || out.sp_flg;
	ft_memset(to_print + p, flg->flags & ZERO ? '0' : ' ', out.num_sp);
	p += out.num_sp;
	ft_strcat(to_print + p, out.number);
}

static t_output		f_output_structure(long double ld, t_flags *flg)
{
	t_output	out;

	ft_bzero(&out, sizeof(t_output));
	out.sign = (ld < 0 || flg->flags & PLUS) ? 1 : 0;
	out.sym = ld < 0 ? '-' : '+';
	out.sp_flg = (flg->flags & SPACE && !out.sign) ? 1 : 0;
	if (ld == 0 && flg->preci & PRECISION && flg->preci == 0)
		out.preci_zero = 1;
	flg->preci = flg->flags & PRECISION ? flg->preci : 6;
	out.number = ft_ftoa((ld < 0 ? -ld : ld), flg->preci);
	out.len = ft_strlen(out.number);
	if (flg->width < out.len + (out.sign || out.sp_flg))
	   flg->width = out.len + (out.sign || out.sp_flg);
	return (out);
}

static long double	ft_get_f(t_vaio *v, t_flags *flg)
{
	long double	ld;
	double		d;

	if (flg->flags & BIGL)
		ld = va_arg(v->ap, long double);
	else
	{
		d = va_arg(v->ap, double);
		ld = (long double)d;
	}
	return (ld);
}

int			ft_f(t_vaio *v, t_flags *flg)
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
	return (flg->width);
}
