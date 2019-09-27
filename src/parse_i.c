/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:10:42 by pberge            #+#    #+#             */
/*   Updated: 2019/09/27 21:25:49 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_itoa_unsigned(long long n)
{
	char		*integer;
	int			len;
	long long	tmp;

	len = 1;
	if (n == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
		n *= -1;
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	if (!(integer = (char *)malloc(len + 1)))
		return (NULL);
	integer[len] = '\0';
	while (len--)
	{
		integer[len] = n % 10 + '0';
		n /= 10;
	}
	return (integer);
}

t_flags	align_left(t_flags flg, long long iparam, char *to_print)
{
	char	*integer;
	int		ilen;
	int		sign;
	char	sym;
	int		num_spaces;
	int		sp;
	int		zero;

	zero = (iparam == 0 && flg.flags & PRECISION && flg.precision == 0) ? 1 : 0;
	sym = iparam < 0 ? '-' : '+';
	sign = (iparam < 0 || flg.flags & PLUS) ? 1 : 0;
	sp = (flg.flags & SPACE && !sign) ? 1 : 0;	
	integer = ft_itoa_unsigned(iparam);
	ilen = !zero ? ft_strlen(integer) : 0;
	flg.width = flg.width < ilen + (sign || sp) ? ilen + (sign || sp) : flg.width;
	flg.width = flg.width < flg.precision ? flg.precision + (sign || sp) : flg.width;
	flg.precision = flg.precision > ilen ? flg.precision - ilen : 0;
	num_spaces = flg.width - (sign || sp) - flg.precision - ilen;
	ft_memset(to_print, ' ', sp);
	ft_memset(to_print + sp, sym, sign);
	ft_memset(to_print + sp + sign, '0', flg.precision);
	if (!zero)
		ft_strcat(to_print, integer);
	ft_memset(to_print + sp + sign + flg.precision + ilen, ' ', num_spaces);
	return (flg);
}

t_flags	align_right(t_flags flg, long long iparam, char *to_print)
{
	char	*integer;
	int		ilen;
	int		sign;
	char	sym;
	int		num_spaces;
	int		sp;
	int		zero;

	zero = (iparam == 0 && flg.flags & PRECISION && flg.precision == 0) ? 1 : 0;
	sp = flg.flags & SPACE ? 1 : 0;
	sym = iparam < 0 ? '-' : '+';
	sign = (iparam < 0 || flg.flags & PLUS) ? 1 : 0;
	integer = ft_itoa_unsigned(iparam);
	ilen = !zero ? ft_strlen(integer) : 0;
	flg.width = flg.width < ilen + (sign || sp) ? ilen + (sign || sp) : flg.width;
	flg.width = flg.width < flg.precision ? flg.precision + (sign || sp) : flg.width;
	if (flg.flags & PRECISION)
		flg.precision = flg.precision > ilen ? flg.precision - ilen : 0;
	else if (flg.flags & ZERO)
		flg.precision = flg.width - (sign || sp) - ilen;
	num_spaces = flg.width - sign - flg.precision - ilen;
	ft_memset(to_print, ' ', num_spaces);
	ft_memset(to_print + num_spaces, sym, sign);
	ft_memset(to_print + num_spaces + sign, '0', flg.precision);	
	if (!zero)
		ft_strcat(to_print, integer);
	return (flg);
}

long long	get_number(va_list ap, char length)
{
	long long	iparam;
	signed char	scp;
	short		sp;
	long long	llp;
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
	else if (length == LLMOD)
		iparam = va_arg(ap, long long);
	else
	{
		ip = va_arg(ap, int);
		iparam = ip;
	}
	return (iparam);
}

int		parse_int(t_vaio *v, t_flags flg)
{
	long long	iparam;
	char		*integer;

	iparam = get_number(v->ap, flg.length);
//	iparam = va_arg(v->ap, int);
	if (flg.flags & MINUS)
		flg = align_left(flg, iparam, v->to_print + v->len);
	else
		flg = align_right(flg, iparam, v->to_print + v->len);
	return (flg.width);
}
