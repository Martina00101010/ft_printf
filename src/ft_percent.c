/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:48:28 by pberge            #+#    #+#             */
/*   Updated: 2019/10/02 19:15:29 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_percent(t_vaio *v, t_flags *flg)
{
	char	*tmp;

	flg->width = flg->width > 1 ? flg->width : 1;
	ft_refresh_buffer(v, flg->width);
	if (flg->flags & MINUS)
	{
		v->to_print[v->len] = '%';
		ft_memset(v->to_print + v->len + 1, ' ', flg->width - 1);
	}
	else
		ft_strrcpy(v->to_print + v->len + flg->width - 1, "%", 1,
			flg->flags & ZERO ? '0' : ' ');
	return (flg->width);
}
