/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:48:28 by pberge            #+#    #+#             */
/*   Updated: 2019/10/05 08:12:25 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_percent(t_vaio *v, t_flags *flg)
{
	char	*to_print;

	flg->width = flg->width > 1 ? flg->width : 1;
	ft_refresh_buffer(v, flg->width);
	to_print = v->to_print + v->len;
	if (flg->flags & MINUS)
	{
		ft_memset(to_print, '%', 1);
		ft_memset(to_print + 1, ' ', flg->width - 1);
	}
	else
	{
		ft_memset(to_print, (flg->flags & ZERO) ? '0' : ' ', flg->width - 1);
		ft_memset(to_print + flg->width - 1, '%', 1);
	}
	return (flg->width);
}
