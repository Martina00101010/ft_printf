/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:35:59 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 19:15:55 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

/*
** taking string from va list ; applying flags to string
*/

int		ft_s(t_vaio *v, t_flags *flg)
{
	char	*sparam;
	int		slen;
	int		cpylen;
	char	*tmp;

	sparam = va_arg(v->ap, char *);
	sparam = (sparam == NULL) ? "(null)" : sparam;
	slen = ft_strlen(sparam);
	if ((flg->flags & PRECISION))
		slen = flg->preci < slen ? flg->preci : slen;
	cpylen = flg->width > slen ? flg->width : slen;
	ft_refresh_buffer(v, cpylen);
	if (flg->flags & MINUS)
	{
		ft_strncat(v->to_print, sparam, slen);
		ft_memset(v->to_print + v->len + slen, ' ', cpylen - slen);
	}
	else
		ft_strrcpy(v->to_print + v->len + cpylen - 1, sparam + slen - 1, slen,
					(flg->flags & ZERO ? '0' : ' '));
	return (cpylen);
}
