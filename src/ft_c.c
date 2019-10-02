/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 02:19:36 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 19:12:25 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_c(t_vaio *v, t_flags *flg)
{
	unsigned char	c;
	char			*to_print;

	c = va_arg(v->ap, int);
	flg->width = (flg->width == 0) ? 1 : flg->width;
	ft_refresh_buffer(v, flg->width);
	to_print = v->to_print + v->len;
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
