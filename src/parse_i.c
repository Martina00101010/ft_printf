/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:10:42 by pberge            #+#    #+#             */
/*   Updated: 2019/09/21 12:26:09 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static char	*ft_itoa_unsigned(int n)
{
	char	*integer;
	int		len;
	int		tmp;

	len = 1;
	if (n == -2147483648)
		return (strdup("2147483648"));
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

t_flags	align_left(t_flags flg, int iparam, char *to_print)
{
	char	*integer;
	int		ilen;
	int		sign;
	char	sym;
	int		num_spaces;

	sym = iparam < 0 ? '-' : '+';
	sign = (iparam < 0 || flg.flags & PLUS) ? 1 : 0;
	integer = ft_itoa_unsigned(iparam);
	ilen = ft_strlen(integer);
	flg.width = flg.width < ilen + sign ? ilen + sign : flg.width;
	flg.width = flg.width < flg.precision ? flg.precision + sign : flg.width;
	flg.precision = flg.precision > ilen ? flg.precision - ilen : 0;
	num_spaces = flg.width - sign - flg.precision - ilen;
	ft_memset(to_print, sym, sign);
	ft_memset(to_print + sign, '0', flg.precision);
	ft_strcat(to_print, integer);
	ft_memset(to_print + sign + flg.precision + ilen, ' ', num_spaces);
	return (flg);
}

t_flags	align_right(t_flags flg, int iparam, char *to_print)
{
	char	*integer;
	int		ilen;
	int		sign;
	char	sym;
	int		num_spaces;

	sym = iparam < 0 ? '-' : '+';
	sign = (iparam < 0 || flg.flags & PLUS) ? 1 : 0;
	integer = ft_itoa_unsigned(iparam);
	ilen = ft_strlen(integer);
	flg.width = flg.width < ilen + sign ? ilen + sign : flg.width;
	flg.width = flg.width < flg.precision ? flg.precision + sign: flg.width;
	flg.precision = flg.precision > ilen ? flg.precision - ilen : 0;
	//flg.precision = (flg.precision < ilen && (flg.flags & ZERO)) ? flg.width - ilen : flg.precision;
	num_spaces = flg.width - sign - flg.precision - ilen;
	ft_memset(to_print, ' ', num_spaces);
	ft_memset(to_print + num_spaces, sym, sign);
	ft_memset(to_print + num_spaces + sign, '0', flg.precision);	
	ft_strcat(to_print, integer);
	return (flg);
}

int		parse_int(t_vaio *v, t_flags flg)
{
	int		iparam;
	char	*integer;

	iparam = va_arg(v->ap, int);
	if (flg.flags & MINUS)
		flg = align_left(flg, iparam, v->to_print + v->len);
	else
		flg = align_right(flg, iparam, v->to_print + v->len);
	return (flg.width);
}
