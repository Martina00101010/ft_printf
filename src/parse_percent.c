/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:48:28 by pberge            #+#    #+#             */
/*   Updated: 2019/09/30 17:48:56 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parse_percent(t_vaio *v, t_flags flg)
{
	char	*tmp;
	int		len;

	len = flg.width > 1 ? flg.width : 1;
	if (flg.flags & MINUS)
	{
		v->to_print[v->len] = '%';
		ft_memset(v->to_print + v->len + 1, ' ', len - 1);
	}
	else
		ft_strrcpy(v->to_print + v->len + len - 1, "%", 1,
			flg.flags & ZERO ? '0' : ' ');
	return (len);
}
