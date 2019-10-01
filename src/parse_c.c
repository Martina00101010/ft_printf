/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 02:19:36 by pberge            #+#    #+#             */
/*   Updated: 2019/10/01 03:32:32 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parse_char(t_vaio *v, t_flags *flg)
{
	unsigned char	c;
	char			*to_print;

	to_print = v->to_print + v->len;
	c = va_arg(v->ap, int);
	flg->width = (flg->width == 0) ? 1 : flg->width;
	if (flg->flags & MINUS)
	{
		ft_memset(to_print, c, 1);
		ft_memset(to_print + 1, ' ', flg->width - 1);
	}
	else
	{
		ft_memset(to_print, ' ', flg->width - 1);
		ft_memset(to_print + flg->width - 1, c, 1);
	}
	return (flg->width);
}
